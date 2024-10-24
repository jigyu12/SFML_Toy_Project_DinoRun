#include "pch.h"

int main()
{
    srand(time(NULL));

    GET_SINGLETON(Game).Init(1920, 1080, "Dino Run");
    GET_SINGLETON(Game).Do();
    GET_SINGLETON(Game).Release();

    return 0;
}