#pragma once

#include "ccollisionproperty.hpp"
#include "centityinstance.hpp"
#include "cgamescenenode.hpp"

// This is not from the game, it was written by me.
struct BBox_t {
    float x, y, w, h;
};

class C_BaseEntity : public CEntityInstance {
   public:
    bool IsBasePlayerController();
    bool IsBasePlayerWeapon();
    bool IsChicken();
    bool IsViewModel();

    const Vector& GetOrigin();
    bool GetBoundingBox(BBox_t& out, bool computeSurroundingBox = false);
    bool ComputeHitboxSurroundingBox(Vector& mins, Vector& maxs);
    float DistanceToSquared(C_BaseEntity* pEntity);

    SCHEMA_FIELD(m_pGameSceneNode, "C_BaseEntity", "m_pGameSceneNode",
                 CGameSceneNode*);
    SCHEMA_FIELD(m_pCollision, "C_BaseEntity", "m_pCollision",
                 CCollisionProperty*);
    SCHEMA_FIELD(m_iTeamNum, "C_BaseEntity", "m_iTeamNum", uint8_t);
    SCHEMA_FIELD(m_hOwnerEntity, "C_BaseEntity", "m_hOwnerEntity", CHandle);
};
