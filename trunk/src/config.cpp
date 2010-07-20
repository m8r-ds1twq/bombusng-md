#include "config.h"
#include "Sysinfo.h"

#define CONFIG_FILE L"config\\preferences.bin"

Config::ref Config::instance=Config::ref();

Config::ref Config::getInstance() {
	if (!instance) {
        instance=Config::ref(new Config());
	}
	return instance;
}

Config::Config(void){
    Serialize s(CONFIG_FILE, Serialize::READ);
    serialize(s);
}

extern std::wstring appRootPath;
void Config::save() {
    std::wstring configPath=appRootPath+L"config";
    CreateDirectory(configPath.c_str(), NULL);

    Serialize s(CONFIG_FILE, Serialize::WRITE);
    serialize(s);
}


void Config::serialize( Serialize &s ) {

    //////////////////////////////////////////////////////////////////////////
    // Serialization
    int version=1;
    s.streamInt(version, 1);
    
    s.streamBool(showOfflines, true);
	s.streamBool(editx2, true);
    //message events
    s.streamBool(composing, true);
    s.streamBool(delivered, true);

    //local history
    s.streamBool(history, true);

    //signalling
	s.streamBool(blink, false);
	s.streamBool(blink2, false);
    s.streamBool(vibra, true);
    s.streamBool(sounds, true);
	s.streamBool(sounds_status, true);
    s.streamBool(vs_status, false);
	s.streamBool(scomposing, true);

    s.streamBool(showGroups, true);						// показывать группы7
    s.streamBool(sortByStatus, true);
    s.streamBool(vsmess, false);
	s.streamBool(vstrymess, false);
    //SIP control
    s.streamBool(raiseSIP, false);
	s.streamBool(sip2, true);

	//std::string tempav=;
	//s.streamString(avtomessage,tempav.c_str());
    s.streamString(avtomessage,(char *)"Autostatus: ");

    //Automatic connection
    s.streamBool(connectOnStartup, false);				//автоматическое соединение. при запуске?


	//Presences
	s.streamBool(showMucPresences, true);
	s.streamBool(showStatusInSimpleChat, true);
	//History
	s.streamBool(saveHistoryMuc, false);
	s.streamBool(saveHistoryHtml, false);
	s.streamBool(confchat, true);
	s.streamBool(confclient, true);
	s.streamBool(is_gmenu, false);                         //граф меню 
	s.streamInt(avatarWidth, 50);
	s.streamInt(tabconf, 1);							// размер табов
	
	s.streamInt(reconnectTries, 3);						// кол-во попыток реконнекта
	s.streamInt(tolshina, 600);							// толщина ? 
	s.streamInt(menu_Weight, 600);	
	// настройка высоты и ширины шрифтов для qVGA для VGA 
	if (sysinfo::screenIsWVGA())
	{
		s.streamInt(msg_font_height,30);					// высота
		s.streamInt(msg_font_width,10);
		s.streamInt(roster_font_height,30);
		s.streamInt(roster_font_width,10);
		s.streamInt(menu_Height,30);
		s.streamInt(menu_Width,10);
	} else if (sysinfo::screenIsVGA())	{
		s.streamInt(msg_font_height,30);					// высота
		s.streamInt(msg_font_width,10);
		s.streamInt(roster_font_height,30);
		s.streamInt(roster_font_width,10);
		s.streamInt(menu_Height,30);
		s.streamInt(menu_Width,10);
	} else 	{
		s.streamInt(msg_font_height,15);					// высота
		s.streamInt(msg_font_width,6);
		s.streamInt(roster_font_height,16);
		s.streamInt(roster_font_width,6);
		s.streamInt(menu_Height,16);
		s.streamInt(menu_Width,6);
	};

	s.streamInt(time_avtostatus,300);
	s.streamInt(ping_aliv,150);
	s.streamInt(pong_aliv,90);
	s.streamInt(id_avtostatus,3);
	s.streamBool(autojoinroom,false);
	s.streamBool(avtostatus, false);
	s.streamBool(tune_status, false);
	s.streamBool(his_muc_d, true);
	s.streamBool(his_ch_d, true);
	s.streamBool(tune_status_pep, false);
    s.streamBool(xmllog, false);
	s.streamBool(isLOG, false);

	s.streamInt(vibra_port, 0);
	s.streamBool(dop_infa, false);
	s.streamBool(signals_muc, true);
	s.streamBool(enter2, true);
	s.streamBool(anim_smile, true);
	s.streamInt(timer_int, 350);
	s.streamString(colorfile,(char *)"color.txt");

}