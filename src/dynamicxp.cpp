/*
Credits
Module Created by Micrah/Milestorme
Script from https://github.com/conan513 Single Player Project 
*/
#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"


class spp_dynamic_xp_rate : public PlayerScript
{
    public:
        spp_dynamic_xp_rate() : PlayerScript("spp_dynamic_xp_rate") { };

        void OnLogin(Player* player) override
       {
            if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate.Announce", true))
               {
               ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Level Dynamic XP |rmodule.");
               }
       }
        void OnGiveXP(Player* player, uint32& /*amount*/, Unit* /*victim*/) override
       {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        
	   {
            if (player->getLevel() >= 1)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1), 0);

            if (player->getLevel() >= 10)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2), 0);

            if (player->getLevel() >= 20)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3), 0);

            if (player->getLevel() >= 30)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4), 0);

            if (player->getLevel() >= 40)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5), 0);

            if (player->getLevel() >= 50)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6), 0);

            if (player->getLevel() >= 60)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7), 0);

            if (player->getLevel() >= 70)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8), 0);
        }

     }
    void OnLevelChanged(Player * player, uint8 oldLevel) override
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
            if (player->getLevel() >= 1)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1), 0);

            if (player->getLevel() >= 10)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2), 0);

            if (player->getLevel() >= 20)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3), 0);

            if (player->getLevel() >= 30)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4), 0);

            if (player->getLevel() >= 40)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5), 0);

            if (player->getLevel() >= 50)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6), 0);

            if (player->getLevel() >= 60)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7), 0);

            if (player->getLevel() >= 70)
                player->GiveXP(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8), 0);

        }
    }
};

void AddSC_dynamic_xp_rate()
{
    new spp_dynamic_xp_rate();
}
