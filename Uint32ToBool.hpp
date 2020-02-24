#pragma once

class Uint32ToBool{
public:
    bool operator()(uint32_t value){return (value > 0 ? true : false);}
    uint32_t operator()(bool value){return (value ? uint32_t(1) : uint32_t(0));}
};
