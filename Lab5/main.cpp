#pragma once
#include <cassert>
#include <iostream>

#include "Lawn.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace lab5;
using namespace std;

void Test1()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Lawn* lawn = new RectangleLawn(4, 5);
	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;
	unsigned int area = lawn->GetArea();
	unsigned int grassPrice = lawn->GetGrassPrice(PERENNIAL_RYEGRASS);
	unsigned int sodRollsCount = lawn->GetMinimumSodRollsCount();
	unsigned int fencesCount = rectangleLawn->GetMinimumFencesCount();
	unsigned int fencePrice = rectangleLawn->GetFencePrice(SPRUCE);
	assert(area == 20);
	assert(grassPrice == 50);
	assert(sodRollsCount == 67);
	assert(fencesCount == 72);
	assert(fencePrice == 126);
	rectangleLawn = nullptr;
	delete lawn;
	cout << "RectangleLawn Clear!" << endl;

	lawn = new EquilateralTriangleLawn(7);
	EquilateralTriangleLawn* equilateralTriangleLawn = (EquilateralTriangleLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(ST_AUGUSTINE);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = equilateralTriangleLawn->GetFencePrice(RED_CEDAR);
	fencesCount = equilateralTriangleLawn->GetMinimumFencesCount();
	assert(area == 21);
	assert(grassPrice == 95);
	assert(sodRollsCount == 70);
	assert(fencePrice == 126);
	assert(fencesCount == 84);
	equilateralTriangleLawn = nullptr;
	delete lawn;

	lawn = new EquilateralTriangleLawn(4);
	equilateralTriangleLawn = (EquilateralTriangleLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(BAHIA);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = equilateralTriangleLawn->GetFencePrice(RED_CEDAR);
	fencesCount = equilateralTriangleLawn->GetMinimumFencesCount();
	assert(area == 7);
	assert(grassPrice == 35);
	assert(sodRollsCount == 24);
	assert(fencePrice == 72);
	assert(fencesCount == 48);
	equilateralTriangleLawn = nullptr;
	delete lawn;
	cout << "EquilateralTriangleLawn Clear!" << endl;

	lawn = new SquareLawn(5);
	SquareLawn* squareLawn = (SquareLawn*)lawn;
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(BENTGRASS);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	fencePrice = squareLawn->GetFencePrice(SPRUCE);
	fencesCount = squareLawn->GetMinimumFencesCount();
	assert(area == 25);
	assert(grassPrice == 75);
	assert(sodRollsCount == 84);
	assert(fencePrice == 140);
	assert(fencesCount == 80);
	squareLawn = nullptr;
	delete lawn;
	cout << "SquareLawn Clear!" << endl;

	lawn = new CircleLawn(2);
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(PERENNIAL_RYEGRASS);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	assert(area == 13);
	assert(grassPrice == 33);
	assert(sodRollsCount == 44);
	delete lawn;
	lawn = new CircleLawn(6);
	area = lawn->GetArea();
	grassPrice = lawn->GetGrassPrice(ST_AUGUSTINE);
	sodRollsCount = lawn->GetMinimumSodRollsCount();
	assert(area == 113);
	assert(grassPrice == 509);
	assert(sodRollsCount == 377);
	delete lawn;
	cout << "CircleLawn Clear!" << endl;

}

void Test2() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Lawn* lawn1 = new RectangleLawn(10, 20);
	unsigned int area = lawn1->GetArea();
	cout << "Test Lawn base class - pointing to a inherited RectangleLawn: PASS" << endl;
	assert(area == 200);
	cout << "Test RectangleLawn GetArea() - invoked by Lawn: PASS" << endl;

	unsigned int sodRollsCount = lawn1->GetMinimumSodRollsCount();
	assert(sodRollsCount == 667);
	cout << "Test RectangleLawn GetMinimumSodRollsCount() - invokded by Lawn: PASS" << endl;

	unsigned int grassPrice = lawn1->GetGrassPrice(BERMUDA);
	assert(grassPrice == 1600);
	cout << "Test RectangleLawn GetGrassPrice(BERMUDA) - invoked by Lawn: PASS" << endl;

	grassPrice = lawn1->GetGrassPrice(BAHIA);
	assert(grassPrice == 1000);
	cout << "Test RectangleLawn GetGrassPrice(BAHIA) - invoked by Lawn: PASS" << endl;

	grassPrice = lawn1->GetGrassPrice(BENTGRASS);
	assert(grassPrice == 600);
	cout << "Test RectangleLawn GetGrassPrice(BENTGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice = lawn1->GetGrassPrice(PERENNIAL_RYEGRASS);
	assert(grassPrice == 500);
	cout << "Test RectangleLawn GetGrassPrice(PERENNIAL_RYEGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice = lawn1->GetGrassPrice(ST_AUGUSTINE);
	assert(grassPrice == 900);
	cout << "Test RectangleLawn GetGrassPrice(ST_AUGUSTINE) - invoked by Lawn: PASS" << endl;

	RectangleLawn* rect1 = (RectangleLawn*)lawn1;
	assert(rect1->GetArea() == lawn1->GetArea());
	cout << "Test Rectangle copy constructor: PASS" << endl;

	unsigned int fencesCount = rect1->GetMinimumFencesCount();
	assert(fencesCount == 240);
	cout << "Test Rectangle GetMinimumFencesCount(): PASS" << endl;

	unsigned int fencesPrice = rect1->GetFencePrice(RED_CEDAR);
	assert(fencesPrice == 360);
	cout << "Test Rectangle GetFencewPrice(RED_CEDAR): PASS" << endl;

	fencesPrice = rect1->GetFencePrice(SPRUCE);
	assert(fencesPrice == 420);
	cout << "Test Rectangle GetFencewPrice(SPRUCE): PASS" << endl;

	Lawn* lawn2 = new SquareLawn(20);
	unsigned int area2 = lawn2->GetArea();
	cout << "Test Lawn base class - pointing to a inherited SquareLawn: PASS" << endl;
	assert(area2 == 400);
	cout << "Test SquareLawn GetArea() - invoked by Lawn: PASS" << endl;

	unsigned int sodRollsCount2 = lawn2->GetMinimumSodRollsCount();
	assert(sodRollsCount2 == 1334);
	cout << "Test SquareLawn GetMinimumSodRollsCount() - invokded by Lawn: PASS" << endl;

	unsigned int grassPrice2 = lawn2->GetGrassPrice(BERMUDA);
	assert(grassPrice2 == 3200);
	cout << "Test SquareLawn GetGrassPrice(BERMUDA) - invoked by Lawn: PASS" << endl;

	grassPrice2 = lawn2->GetGrassPrice(BAHIA);
	assert(grassPrice2 == 2000);
	cout << "Test SquareLawn GetGrassPrice(BAHIA) - invoked by Lawn: PASS" << endl;

	grassPrice2 = lawn2->GetGrassPrice(BENTGRASS);
	assert(grassPrice2 == 1200);
	cout << "Test SquareLawn GetGrassPrice(BENTGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice2 = lawn2->GetGrassPrice(PERENNIAL_RYEGRASS);
	assert(grassPrice2 == 1000);
	cout << "Test SquareLawn GetGrassPrice(PERENNIAL_RYEGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice2 = lawn2->GetGrassPrice(ST_AUGUSTINE);
	assert(grassPrice2 == 1800);
	cout << "Test SquareLawn GetGrassPrice(ST_AUGUSTINE) - invoked by Lawn: PASS" << endl;

	SquareLawn* square1 = (SquareLawn*)lawn2;
	assert(square1->GetArea() == lawn2->GetArea());
	cout << "Test Square copy constructor: PASS" << endl;

	unsigned int sqFencesCount = square1->GetMinimumFencesCount();
	assert(sqFencesCount == 320);
	cout << "Test Square GetMinimumFencesCount(): PASS" << endl;

	unsigned int sqFencesPrice = square1->GetFencePrice(RED_CEDAR);
	assert(sqFencesPrice == 480);
	cout << "Test Square GetFencewPrice(RED_CEDAR): PASS" << endl;

	sqFencesPrice = square1->GetFencePrice(SPRUCE);
	assert(sqFencesPrice == 560);
	cout << "Test Square GetFencewPrice(SPRUCE): PASS" << endl;

	Lawn* lawn3 = new EquilateralTriangleLawn(20);
	unsigned int area3 = lawn3->GetArea();
	cout << "Test Lawn base class - pointing to a inherited EquilateralTriangleLawn: PASS" << endl;
	assert(area3 == 173);
	cout << "Test EquilateralTriangleLawn GetArea() - invoked by Lawn: PASS" << endl;

	unsigned int sodRollsCount3 = lawn3->GetMinimumSodRollsCount();
	assert(sodRollsCount3 == 577);
	cout << "Test EquilateralTriangleLawn GetMinimumSodRollsCount() - invokded by Lawn: PASS" << endl;

	unsigned int grassPrice3 = lawn3->GetGrassPrice(BERMUDA);
	assert(grassPrice3 == 1384);
	cout << "Test EquilateralTriangleLawn GetGrassPrice(BERMUDA) - invoked by Lawn: PASS" << endl;

	grassPrice3 = lawn3->GetGrassPrice(BAHIA);
	assert(grassPrice3 == 865);
	cout << "Test EquilateralTriangleLawn GetGrassPrice(BAHIA) - invoked by Lawn: PASS" << endl;

	grassPrice3 = lawn3->GetGrassPrice(BENTGRASS);
	assert(grassPrice3 == 519);
	cout << "Test EquilateralTriangleLawn GetGrassPrice(BENTGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice3 = lawn3->GetGrassPrice(PERENNIAL_RYEGRASS);
	assert(grassPrice3 == 433);
	cout << "Test EquilateralTriangleLawn GetGrassPrice(PERENNIAL_RYEGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice3 = lawn3->GetGrassPrice(ST_AUGUSTINE);
	assert(grassPrice3 == 779);
	cout << "Test EquilateralTriangleLawn GetGrassPrice(ST_AUGUSTINE) - invoked by Lawn: PASS" << endl;

	EquilateralTriangleLawn* triangle1 = (EquilateralTriangleLawn*)lawn3;
	assert(triangle1->GetArea() == lawn3->GetArea());
	cout << "Test Square copy constructor: PASS" << endl;

	unsigned int triFencesCount = triangle1->GetMinimumFencesCount();
	assert(triFencesCount == 240);
	cout << "Test Square GetMinimumFencesCount(): PASS" << endl;

	unsigned int triFencesPrice = triangle1->GetFencePrice(RED_CEDAR);
	assert(triFencesPrice == 360);
	cout << "Test Square GetFencewPrice(RED_CEDAR): PASS" << endl;

	triFencesPrice = triangle1->GetFencePrice(SPRUCE);
	assert(triFencesPrice == 420);
	cout << "Test Square GetFencewPrice(SPRUCE): PASS" << endl;

	Lawn* lawn4 = new CircleLawn(20);
	unsigned int area4 = lawn4->GetArea();
	cout << "Test Lawn base class - pointing to a inherited CircleLawn: PASS" << endl;
	assert(area4 == 1256);
	cout << "Test CircleLawn GetArea() - invoked by Lawn: PASS" << endl;

	unsigned int sodRollsCount4 = lawn4->GetMinimumSodRollsCount();
	assert(sodRollsCount4 == 4187);
	cout << "Test CircleLawn GetMinimumSodRollsCount() - invokded by Lawn: PASS" << endl;

	unsigned int grassPrice4 = lawn4->GetGrassPrice(BERMUDA);
	assert(grassPrice4 == 10048);
	cout << "Test CircleLawn GetGrassPrice(BERMUDA) - invoked by Lawn: PASS" << endl;

	grassPrice4 = lawn4->GetGrassPrice(BAHIA);
	assert(grassPrice4 == 6280);
	cout << "Test CircleLawn GetGrassPrice(BAHIA) - invoked by Lawn: PASS" << endl;

	grassPrice4 = lawn4->GetGrassPrice(BENTGRASS);
	assert(grassPrice4 == 3768);
	cout << "Test CircleLawn GetGrassPrice(BENTGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice4 = lawn4->GetGrassPrice(PERENNIAL_RYEGRASS);
	assert(grassPrice4 == 3140);
	cout << "Test CircleLawn GetGrassPrice(PERENNIAL_RYEGRASS) - invoked by Lawn: PASS" << endl;

	grassPrice4 = lawn4->GetGrassPrice(ST_AUGUSTINE);
	assert(grassPrice4 == 5652);
	cout << "Test CircleLawn GetGrassPrice(ST_AUGUSTINE) - invoked by Lawn: PASS" << endl;

	const unsigned int expectedAreas[] =
	{
		0, 3, 13, 28, 50,
		79, 113, 154, 201, 254,
		314, 380, 452, 531, 615,
		707, 804, 907, 1017, 1134,
		1256, 1385, 1520, 1661, 1809,
		1963, 2123, 2289, 2462, 2641,
		2826
	};

	const unsigned int expectedRollCounts[] =
	{
		0, 10, 44, 94, 167,
		264, 377, 514, 670, 847,
		1047, 1267, 1507, 1770, 2050,
		2357, 2680, 3024, 3390, 3780,
		4187, 4617, 5067, 5537, 6030,
		6544, 7077, 7630, 8207, 8804,
		9420
	};

	Lawn* lawn5 = NULL;
	unsigned int area5 = 0;
	unsigned int rollCount5 = 0;
	for (unsigned int i = 0; i < 31; i++)
	{
		lawn5 = new CircleLawn(i);
		area5 = lawn5->GetArea();
		assert(area5 == expectedAreas[i]);
		cout << "Test Circle Area: radius=" << i << " expected area=" << expectedAreas[i] << " actual area=" << area5 << endl;
		rollCount5 = lawn5->GetMinimumSodRollsCount();
		assert(rollCount5 == expectedRollCounts[i]);
		cout << "Test Circle Area: radius=" << i << " expected count=" << expectedRollCounts[i] << " actual count=" << rollCount5 << endl;
		delete lawn5;
	}

	delete lawn1;
	delete lawn2;
	delete lawn3;
	delete lawn4;


}

int main() {
	Test1();
	Test2();
	return 0;
}