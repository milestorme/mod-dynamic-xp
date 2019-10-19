/*
Credits
Script reworked by Micrah/Milestorme and Poszer (Poszer is the Best)
Module Created by Micrah/Milestorme
Original Script from AshmaneCore https://github.com/conan513 Single Player Project 
*/
#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

float amount;

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
        void OnGiveXP(Player* player, uint32& amount, Unit* /*victim*/) override
       {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        
	   {
           if (player->getLevel() >= 1)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.1-9", 10.0f);

           if (player->getLevel() >= 10)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.10-19", 20.0f);

           if (player->getLevel() >= 20)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.20-29", 30.0f);

           if (player->getLevel() >= 30)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.30-39", 40.0f);

           if (player->getLevel() >= 40)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.40-49", 50.0f);

           if (player->getLevel() >= 50)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.50-59", 60.0f);
           
           if (player->getLevel() >= 60)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.60-69", 70.0f);

           if (player->getLevel() >= 70)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.70-79", 80.0f);
        }

     }
    void OnLevelChanged(Player * player, uint8 /*oldLevel*/) override
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
           if (player->getLevel() >= 1)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.1-9", 10.0f);

           if (player->getLevel() >= 10)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.10-19", 20.0f);

           if (player->getLevel() >= 20)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.20-29", 30.0f);

           if (player->getLevel() >= 30)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.30-39", 40.0f);

           if (player->getLevel() >= 40)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.40-49", 50.0f);

           if (player->getLevel() >= 50)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.50-59", 60.0f);
           
           if (player->getLevel() >= 60)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.60-69", 70.0f);

           if (player->getLevel() >= 70)
            amount *= sConfigMgr->GetFloatDefault("Dynamic.XP.Rate.70-79", 80.0f);

        }
           
    }
};

void AddSC_dynamic_xp_rate()
{
    new spp_dynamic_xp_rate();
}
