#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

class DinoBaraVirtClass
{
public:
	virtual void run() {};
};

class A:DinoBaraVirtClass
{
public:
	  override   run() {};
};

class B :DinoBaraVirtClass
{
};

class C :DinoBaraVirtClass
{
};