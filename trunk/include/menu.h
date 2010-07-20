#ifndef MENU_H
#define MENU_H

#pragma once
#include <windows.h>
#include <vector>
//#include <string>
//#include <stddef.h>

typedef wchar_t character_t;

class Menu;

class MenuElement{
public:

    void setIcon(int icon);
    void setText(const character_t* text);

    void ownerdraw(DRAWITEMSTRUCT* di);
    void measureitem(HDC dc, MEASUREITEMSTRUCT* mi);

protected:
    MenuElement(Menu* rootmenu);
    MenuElement(Menu* rootmenu, const character_t* text, int icon);

    character_t* _text;
    int _icon;
    Menu* _root;
private:
    void getIconSize(SIZE* s);
};

class Menu:
    public MenuElement
{
protected:
    Menu(Menu* rootmenu, const character_t* text, int icon);
public:
    Menu(HWND hWnd);//parent window
    Menu(HWND hWnd,const character_t* text, int icon);
    ~Menu();

    class MenuItem:
        public MenuElement
    {
    public:
    
        friend class Menu;
    
        typedef void (*Handler)(void);
        typedef int itemid_t;
        
        int id();
        void setHandler(Handler proc);
        bool call(itemid_t itemid);
    
        void check(bool ch);
        bool checked();
        
    protected:
        MenuItem(Menu* rootmenu, itemid_t itemid);
        MenuItem(Menu* rootmenu, const character_t* text, int icon, Handler proc);
        MenuItem(Menu* rootmenu, const character_t* text, int icon, Handler proc, itemid_t itemid);

        static int _itemids;
        int _id;
        Handler _handler;
    };

    HMENU hMenu();
    
    void set();
    
    void measure(MEASUREITEMSTRUCT* mi);
    void redraw(DRAWITEMSTRUCT* di);
    
    bool call(MenuItem::itemid_t itemid);

    Menu* addMenu(const character_t* text, int icon);
    MenuItem* addSeparator();
    MenuItem* addItem(const character_t* text, int icon, MenuItem::Handler proc);
    MenuItem* addItem(const character_t* text, int icon, MenuItem::Handler proc, MenuItem::itemid_t itemid);

protected:
    typedef std::vector<Menu*> SubMenus;
    typedef std::vector<MenuItem*> MenuItems;
    SubMenus *_submenus;
    MenuItems *_subitems;

    HWND _hwnd;

    HMENU _hmenu;
};

#endif
