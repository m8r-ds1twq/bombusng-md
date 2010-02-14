#pragma once

#include <string>
#include "boostheaders.h"
#include "Serialize.h"

class Config
{
public:
    ~Config(){};


    typedef boost::shared_ptr<Config> ref;

    static Config::ref getInstance();

    bool showOfflines;					// показывать отключенных
    bool showGroups;					// показывать группы
    bool sortByStatus;					// сортировать по статусу

    bool composing;						// уведомление о наборе
    bool delivered;						// уведомление о доставке
    bool history;						// хранить ли историю локально
	bool blink;
	bool blink2;
    bool vibra;							// включена ли вибра
    bool sounds;						// включен ли звук
	bool sounds_status;
	bool vs_status;
	bool vsmess;
	bool vstrymess;
	bool scomposing;
    bool raiseSIP;
	bool sip2;//скрывать клаву после посылки сообщения
	bool editx2;
    bool connectOnStartup;
	bool confchat;
	bool confclient;
	bool xmllog;
	bool isLOG;
	int avatarWidth;
	int tabconf;
	std::string  avtomessage;
	int reconnectTries;
	int msg_font_width;
	int msg_font_height;
	int roster_font_width;
	int roster_font_height;
	int tolshina;
	int ping_aliv;
	int pong_aliv;
	bool avtostatus;
	bool autojoinroom;
	bool tune_status;
	int  time_avtostatus;
	bool tune_status_pep;
	bool his_ch_d;
	bool his_muc_d;
	//int id_avtostatus;
	bool showMucPresences;
	bool showStatusInSimpleChat;
	bool saveHistoryMuc;
	bool saveHistoryHtml;
	int id_avtostatus;
    void save();
	int vibra_port;
	bool dop_infa;
	bool signals_muc;
	bool enter2;
	bool anim_smile;
	int  timer_int;
	std::string colorfile;
private:
    void serialize(Serialize &s);
    static Config::ref instance;

	Config();
};
