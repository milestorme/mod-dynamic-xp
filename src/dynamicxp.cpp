/*
Credits
Module Created by Micrah/Milestorme
Script from https://github.com/conan513 Single Player Project 
*/
#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

bool Enabled;
uint32 xpAmount1;
uint32 xpAmount2;
uint32 xpAmount3;
uint32 xpAmount4;
uint32 xpAmount5;
uint32 xpAmount6;
uint32 xpAmount7;
uint32 xpAmount8;

class spp_dynamic_xp_rate : public PlayerScript
{
    public:
        spp_dynamic_xp_rate() : PlayerScript("spp_dynamic_xp_rate") { };
        
    void OnLogin(Player* player, bool /*firstLogin*/)
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        ChatHandler(player->GetSession()).PSendSysMessage("Welcome to Wowtorn your XP multiplier has been set to: %u", xpAmount);
       
	   {
            if (player->getLevel() >= 1)
                player->xpAmount1(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1));

            if (player->getLevel() >= 10)
                player->xpAmount2(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2));

            if (player->getLevel() >= 20)
                player->xpAmount3(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3));

            if (player->getLevel() >= 30)
                player->xpAmount4(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4));

            if (player->getLevel() >= 40)
                player->xpAmount5(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5));

            if (player->getLevel() >= 50)
                player->xpAmount6(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6));

            if (player->getLevel() >= 60)
                player->xpAmount7(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7));

            if (player->getLevel() >= 70)
                player->xpAmount8(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8));
        }

        if (!sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
            player->xpAmount(0);
        }

    }
		
    void OnLevelChanged(Player * player, uint8 oldLevel)
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
            if (player->getLevel() >= 1)
                player->xpAmount1(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1));

            if (player->getLevel() >= 10)
                player->xpAmount2(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2));

            if (player->getLevel() >= 20)
                player->xpAmount3(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3));

            if (player->getLevel() >= 30)
                player->xpAmount4(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4));

            if (player->getLevel() >= 40)
                player->xpAmount5(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5));

            if (player->getLevel() >= 50)
                player->xpAmount6(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6));

            if (player->getLevel() >= 60)
                player->xpAmount7(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7));

            if (player->getLevel() >= 70)
                player->xpAmount8(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8));

        }
    }

};
class DynamicXpConf : public WorldScript
{
public:
    DynamicXpConf() : WorldScript("DynamicXpConf") {}

    void OnBeforeConfigLoad(bool reload) override
    {
        if (!reload) {
            std::string conf_path = _CONF_DIR;
            std::string cfg_file = conf_path + "/dynamicxp.conf";

            std::string cfg_def_file = cfg_file + ".dist";
            sConfigMgr->LoadMore(cfg_def_file.c_str());
            sConfigMgr->LoadMore(cfg_file.c_str());

            Enabled = sConfigMgr->GetBoolDefault("XPWeekend.Enabled", true);
            xpAmount1 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1);
			xpAmount2 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2);
			xpAmount3 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3);
			xpAmount4 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4);
			xpAmount5 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5);
			xpAmount6 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6);
			xpAmount7 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7);
			xpAmount8 = sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8);

        }
    }
};

void AddSC_dynamic_xp_rate()
{
    new DynamicXpConf();
    new spp_dynamic_xp_rate();
}