#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

abstract class DinoBaraVirtClass
{
	virtual void run() {};
};

class A:DinoBaraVirtClass
{
	 void o  run() {};
};

class B :DinoBaraVirtClass
{
};

class C :DinoBaraVirtClass
{
};