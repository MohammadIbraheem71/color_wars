#include "cell.h"
#include <iostream>

cell::cell(){
    value = 0;
    owner = player::none;
}

int cell::get_value(){
    return value;
}

void cell::set_owner(player player_value){
    owner = player_value;
}

player cell::get_owner() const{
    return owner;
}

void cell::reset(){
    value = 0;
    owner = player::none;
}

void cell::increment(player player_value){
    value++;
    cell::set_owner(player_value);
    std::cout<<"owner value for cell set to: "<<static_cast<int>(player_value)<<std::endl;
}

bool cell::critical(){
    if (value >= 4){
        return true;
    }

    return false;
}
