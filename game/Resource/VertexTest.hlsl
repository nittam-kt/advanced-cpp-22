// ----------------------------------------------------------
// 頂点
// ----------------------------------------------------------
cbuffer VSConstants : register(b8)
{
    float4 time;
};
cbuffer VSConstants : register(b9)
{
    float4x4 world;
    float4x4 view;
    float4x4 projection;
};

// 頂点シェーダーへ入力するデータ
struct VSInput
{
    float3 pos : POSITION;
};


// 頂点シェーダーから出力＆ピクセルシェーダーへ入力するデータ
struct PSInput
{
    float4 pos   : SV_Position; // 頂点の座標
    float4 color : COLOR;       // カラー
};

// 頂点シェーダー
PSInput VS(VSInput vin)
{
    PSInput Out;
    float4 p = float4(vin.pos.xyz, 1);
    p = mul(world, p);
    p = mul(view, p);
    p = mul(projection, p);
    Out.pos = p;

    Out.color = 1;

    return Out;
}

 
// ----------------------------------------------------------
// ピクセル
// ----------------------------------------------------------
// ピクセルシェーダー
float4 PS(PSInput In) : SV_Target0
{
    // 頂点シェーダーから出力されたカラーを補完した色をそのまま出力
    return float4(In.color.xyz, 1);
}
