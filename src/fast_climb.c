#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

#define CFG_CLIMB_SPEED recomp_get_config_double("climb_speed")
#define CFG_REQUIRE_BUNNY_HOOD (bool)recomp_get_config_u32("require_bunny_hood")

void func_8082E1F0(Player* this, u16 sfxId);
EquipSlot func_8082FDC4(void);
ItemId Player_GetItemOnButton(PlayState* play, Player* player, EquipSlot slot);

RECOMP_HOOK("func_80831944") void func_80831944(PlayState* play, Player* this) {
    if (!CFG_REQUIRE_BUNNY_HOOD || (CFG_REQUIRE_BUNNY_HOOD && this->currentMask == PLAYER_MASK_BUNNY)) {
        this->skelAnime.playSpeed *= CFG_CLIMB_SPEED;
    }
    
    // gPlayerFormItemRestrictions[PLAYER_FORM_HUMAN][ITEM_MASK_BUNNY] = 1;
    // gPlayerFormItemRestrictions[PLAYER_FORM_DEKU][ITEM_MASK_BUNNY] = 1;
    // gPlayerFormItemRestrictions[PLAYER_FORM_GORON][ITEM_MASK_BUNNY] = 1;
    // gPlayerFormItemRestrictions[PLAYER_FORM_ZORA][ITEM_MASK_BUNNY] = 1;
    // gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = BTN_ENABLED;
    // gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = BTN_ENABLED;
    // gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = BTN_ENABLED;



    // this->prevMask = this->currentMask;
    // this->currentMask = PLAYER_MASK_BUNNY;
    // func_8082E1F0(this, NA_SE_PL_CHANGE_ARMS);
    // gSaveContext.save.equippedMask = this->currentMask;
    // if (Player_GetItemOnButton(play, this, EQUIP_SLOT_C_LEFT) == ITEM_MASK_BUNNY) {
    //     gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = BTN_ENABLED;
    // }
    // if (Player_GetItemOnButton(play, this, EQUIP_SLOT_C_DOWN) == ITEM_MASK_BUNNY) {
    //     gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = BTN_ENABLED;
    // }
    // if (Player_GetItemOnButton(play, this, EQUIP_SLOT_C_RIGHT) == ITEM_MASK_BUNNY) {
    //     gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = BTN_ENABLED;
    // }
    


    if (Player_GetItemOnButton(play, this, func_8082FDC4()) == ITEM_MASK_BUNNY) {
        
        this->prevMask = this->currentMask;
        if (this->currentMask == PLAYER_MASK_BUNNY) {
            this->currentMask = PLAYER_MASK_NONE;
            func_8082E1F0(this, NA_SE_PL_TAKE_OUT_SHIELD);
        } else {
            this->currentMask = PLAYER_MASK_BUNNY;
            func_8082E1F0(this, NA_SE_PL_CHANGE_ARMS);
        }
        gSaveContext.save.equippedMask = this->currentMask;
    }
}