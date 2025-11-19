#pragma once

#include "UniDxDefine.h"

namespace UniDx {

// UniDxで使用する定数バッファのスロット番号
// すべてのシェーダーはこの番号に従って指定する
enum CbSlot : uint8_t
{
    CB_UserStart = 0,        // ゲーム用バッファの開始番号
    CB_User0 = CB_UserStart,
    CB_User1 = CB_UserStart + 1,
    CB_User2 = CB_UserStart + 2,
    CB_User3 = CB_UserStart + 3,

    CB_PerFrame = 8,        // フレーム共通
    CB_PerObject = 9,       // オブジェクトごと
    CB_PerMaterial = 10,    // マテリアルごと
};


// -----------------------------------------------------------------------------
// シェーダー側と共有する、時間定数バッファ
// -----------------------------------------------------------------------------
struct ConstantBufferPerFrame
{
    Vector4 time;       // (t, dt, 1/dt, frameCount)
};


// -----------------------------------------------------------------------------
// シェーダー側と共有する、モデルビュー行列の定数バッファ
// -----------------------------------------------------------------------------
struct ConstantBufferPerObject
{
    Matrix world;
    Matrix view;
    Matrix projection;
};


// -----------------------------------------------------------------------------
// シェーダー側と共有する、マテリアルの定数バッファ
// -----------------------------------------------------------------------------
struct ConstantBufferPerMaterial
{
    Color baseColor;
};

}