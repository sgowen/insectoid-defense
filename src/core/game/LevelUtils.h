//
//  LevelUtils.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 10/13/13.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__LevelUtils__
#define __insectoiddefense__LevelUtils__

#include <string>

class LevelUtils
{
public:
	static int getPointsScalarForDifficulty(int difficulty)
	{
		return difficulty == 0 ? 17 : difficulty == 1 ? 36 : 50;
	}

	static int calculateStartingFunds(int levelIndex, int difficulty)
	{
		switch (levelIndex)
		{
		case 0:
			return difficulty == 0 ? 80 : difficulty == 1 ? 40 : 20;
		case 1:
			return difficulty == 0 ? 120 : difficulty == 1 ? 80 : 40;
		case 2:
			return difficulty == 0 ? 400 : difficulty == 1 ? 350 : 300;
		case 3:
			return difficulty == 0 ? 90 : difficulty == 1 ? 60 : 30;
		case 4:
			return difficulty == 0 ? 200 : difficulty == 1 ? 150 : 100;
		case 5:
			return difficulty == 0 ? 400 : difficulty == 1 ? 350 : 300;
		case 6:
			return difficulty == 0 ? 120 : difficulty == 1 ? 80 : 40;
		case 7:
			return difficulty == 0 ? 700 : difficulty == 1 ? 600 : 500;
		case 8:
			return difficulty == 0 ? 300 : difficulty == 1 ? 240 : 180;
		case 9:
			return difficulty == 0 ? 500 : difficulty == 1 ? 450 : 400;
		default:
			return 0;
		}
	}

	// bsp = blank space
	// pso = solo platform
	// ptl = top left platform
	// ptr = top right platform
	// pbl = bottom left platform
	// pbr = bottom right platform
	// pcp = center platform
	// php = horizontal platform
	// pvp = vertical platform
	// ptt = top three way platform
	// pbt = bottom three way platform
	// plt = left three way platform
	// prt = right three way platform
	// pet = end top platform
	// peb = end bottom platform
	// pel = end left platform
	// per = end right platform
	// spp = spawn point
	// gop = goal point
	static std::vector<std::string> getRowsForLevelIndex(int levelIndex)
	{
		static std::vector<std::string> level_1_rows;
		static std::vector<std::string> level_2_rows;
		static std::vector<std::string> level_3_rows;
		static std::vector<std::string> level_4_rows;
		static std::vector<std::string> level_5_rows;
		static std::vector<std::string> level_6_rows;
		static std::vector<std::string> level_7_rows;
		static std::vector<std::string> level_8_rows;
		static std::vector<std::string> level_9_rows;
		static std::vector<std::string> level_10_rows;

		if (level_1_rows.size() == 0)
		{
			level_1_rows.push_back("pel,php,php,ptt,php,php,php,php,php,php,ptr");
			level_1_rows.push_back("bsp,bsp,bsp,pvp,bsp,bsp,bsp,bsp,bsp,bsp,pvp");
			level_1_rows.push_back("bsp,pet,bsp,pvp,bsp,ptl,php,php,per,bsp,pvp");
			level_1_rows.push_back("bsp,pvp,bsp,pvp,bsp,pvp,bsp,bsp,bsp,bsp,pvp");
			level_1_rows.push_back("bsp,pvp,bsp,pvp,bsp,pvp,bsp,ptl,ptt,ptt,prt");
			level_1_rows.push_back("bsp,pvp,bsp,pvp,bsp,pvp,bsp,plt,pbt,pbt,pbr");
			level_1_rows.push_back("bsp,pvp,bsp,peb,bsp,pvp,bsp,pvp,bsp,bsp,bsp");
			level_1_rows.push_back("bsp,pvp,bsp,bsp,bsp,pvp,bsp,peb,bsp,pet,gop");
			level_1_rows.push_back("spp,pbl,php,php,php,pbr,bsp,bsp,bsp,pbl,per");

			level_2_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,pel,ptr,bsp,bsp,bsp");
			level_2_rows.push_back("bsp,pel,php,php,per,bsp,bsp,pvp,bsp,pso,bsp");
			level_2_rows.push_back("bsp,bsp,bsp,bsp,bsp,pet,bsp,pvp,bsp,bsp,bsp");
			level_2_rows.push_back("pel,php,php,ptr,bsp,pvp,bsp,pvp,bsp,pet,bsp");
			level_2_rows.push_back("spp,bsp,bsp,pvp,bsp,pvp,bsp,peb,bsp,pvp,bsp");
			level_2_rows.push_back("pel,ptr,bsp,pvp,bsp,pvp,bsp,bsp,bsp,pvp,gop");
			level_2_rows.push_back("bsp,pvp,bsp,pvp,bsp,pvp,bsp,pet,bsp,pvp,bsp");
			level_2_rows.push_back("bsp,pvp,bsp,peb,bsp,pvp,bsp,pvp,bsp,peb,bsp");
			level_2_rows.push_back("pel,pbr,bsp,bsp,bsp,peb,bsp,peb,bsp,bsp,bsp");

			level_3_rows.push_back("bsp,bsp,bsp,pel,ptt,per,bsp,ptl,php,php,ptr");
			level_3_rows.push_back("bsp,pet,bsp,bsp,peb,bsp,bsp,pvp,bsp,spp,pvp");
			level_3_rows.push_back("spp,plt,per,bsp,bsp,bsp,pel,prt,bsp,bsp,pvp");
			level_3_rows.push_back("bsp,pvp,bsp,bsp,pet,bsp,bsp,pvp,bsp,ptl,prt");
			level_3_rows.push_back("bsp,pvp,bsp,pel,pcp,per,bsp,pvp,bsp,plt,pbr");
			level_3_rows.push_back("bsp,pvp,bsp,bsp,peb,bsp,bsp,pvp,bsp,pvp,gop");
			level_3_rows.push_back("bsp,plt,per,bsp,bsp,bsp,pel,prt,bsp,peb,bsp");
			level_3_rows.push_back("bsp,peb,bsp,bsp,pet,bsp,bsp,peb,bsp,bsp,bsp");
			level_3_rows.push_back("bsp,bsp,bsp,pel,pbt,per,bsp,bsp,bsp,pel,per");

			level_4_rows.push_back("ptl,php,ptt,php,php,php,ptt,php,php,php,ptr");
			level_4_rows.push_back("pvp,spp,pvp,bsp,bsp,bsp,pvp,bsp,bsp,bsp,pvp");
			level_4_rows.push_back("pvp,bsp,pvp,bsp,pet,bsp,pvp,bsp,pet,bsp,peb");
			level_4_rows.push_back("pvp,bsp,pvp,bsp,pvp,bsp,pvp,bsp,pvp,bsp,gop");
			level_4_rows.push_back("pvp,bsp,pvp,bsp,pvp,bsp,pvp,bsp,plt,ptt,ptr");
			level_4_rows.push_back("pvp,bsp,pvp,bsp,pvp,bsp,pvp,bsp,plt,pcp,prt");
			level_4_rows.push_back("pvp,bsp,peb,bsp,pvp,bsp,peb,bsp,plt,pcp,prt");
			level_4_rows.push_back("pvp,bsp,bsp,bsp,pvp,bsp,bsp,bsp,plt,pcp,prt");
			level_4_rows.push_back("pbl,php,php,php,pbt,php,php,php,pbt,pbt,pbr");

			level_5_rows.push_back("pso,bsp,spp,pet,bsp,bsp,bsp,bsp,bsp,bsp,pso");
			level_5_rows.push_back("bsp,bsp,pel,pbr,bsp,ptl,php,php,per,bsp,gop");
			level_5_rows.push_back("bsp,pso,bsp,bsp,bsp,pvp,bsp,bsp,bsp,pet,bsp");
			level_5_rows.push_back("bsp,bsp,bsp,pet,bsp,pvp,bsp,pet,bsp,pvp,bsp");
			level_5_rows.push_back("pel,php,php,pcp,php,prt,bsp,pvp,bsp,pvp,bsp");
			level_5_rows.push_back("bsp,bsp,bsp,peb,bsp,pvp,bsp,pvp,bsp,pvp,bsp");
			level_5_rows.push_back("bsp,pso,bsp,bsp,bsp,pvp,bsp,pvp,bsp,peb,bsp");
			level_5_rows.push_back("bsp,bsp,pel,ptr,bsp,peb,bsp,pvp,bsp,bsp,bsp");
			level_5_rows.push_back("pso,bsp,spp,peb,bsp,bsp,bsp,peb,bsp,pel,per");

			level_6_rows.push_back("bsp,spp,bsp,spp,bsp,spp,bsp,spp,bsp,spp,bsp");
			level_6_rows.push_back("pet,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,pet");
			level_6_rows.push_back("plt,php,php,php,per,bsp,pel,php,php,php,pbr");
			level_6_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp");
			level_6_rows.push_back("pvp,bsp,pel,php,php,php,php,php,php,per,bsp");
			level_6_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp");
			level_6_rows.push_back("pvp,bsp,pso,bsp,pel,php,php,php,php,php,per");
			level_6_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,gop");
			level_6_rows.push_back("pbl,php,php,php,php,php,php,php,php,php,per");

			level_7_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,spp,pso");
			level_7_rows.push_back("bsp,pel,php,php,php,php,php,php,php,ptr,gop");
			level_7_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,pvp,bsp");
			level_7_rows.push_back("pel,php,php,ptt,php,php,php,ptr,bsp,pvp,bsp");
			level_7_rows.push_back("bsp,bsp,bsp,pvp,bsp,bsp,bsp,pvp,bsp,pvp,bsp");
			level_7_rows.push_back("bsp,pet,bsp,peb,bsp,pet,bsp,peb,bsp,pvp,bsp");
			level_7_rows.push_back("bsp,pvp,bsp,bsp,bsp,pvp,bsp,bsp,bsp,pvp,bsp");
			level_7_rows.push_back("bsp,pbl,php,php,php,pbt,php,php,php,pbr,bsp");
			level_7_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp");

			level_8_rows.push_back("spp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp");
			level_8_rows.push_back("ptl,ptt,php,php,php,per,bsp,pel,ptt,ptr,spp");
			level_8_rows.push_back("pbl,pbr,bsp,bsp,bsp,bsp,bsp,bsp,plt,pcp,per");
			level_8_rows.push_back("bsp,bsp,bsp,ptl,php,php,ptr,bsp,pbl,prt,gop");
			level_8_rows.push_back("bsp,pet,bsp,pvp,bsp,spp,pvp,bsp,bsp,pvp,bsp");
			level_8_rows.push_back("bsp,pvp,bsp,pvp,bsp,pel,pbt,per,bsp,pvp,bsp");
			level_8_rows.push_back("bsp,pvp,bsp,pvp,bsp,bsp,bsp,bsp,bsp,pvp,bsp");
			level_8_rows.push_back("bsp,pvp,bsp,pbl,php,php,php,php,php,pbr,bsp");
			level_8_rows.push_back("spp,peb,spp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp");

			level_9_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,spp");
			level_9_rows.push_back("bsp,pel,ptt,ptt,php,php,php,ptt,php,php,per");
			level_9_rows.push_back("bsp,bsp,pbl,prt,bsp,bsp,bsp,pvp,bsp,bsp,bsp");
			level_9_rows.push_back("pet,bsp,bsp,pvp,bsp,pet,bsp,pvp,bsp,pet,bsp");
			level_9_rows.push_back("plt,per,bsp,peb,bsp,pvp,bsp,pvp,bsp,pvp,bsp");
			level_9_rows.push_back("peb,bsp,bsp,bsp,bsp,pvp,bsp,peb,bsp,pvp,gop");
			level_9_rows.push_back("bsp,bsp,ptl,ptt,ptt,prt,bsp,bsp,bsp,plt,ptr");
			level_9_rows.push_back("bsp,pel,pbt,pbt,pbt,pbt,php,php,php,pbt,pbr");
			level_9_rows.push_back("bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,spp");

			level_10_rows.push_back("pet,bsp,spp,pet,spp,pet,spp,ptl,php,php,per");
			level_10_rows.push_back("pvp,bsp,pel,pbr,bsp,peb,bsp,pvp,bsp,bsp,bsp");
			level_10_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,pvp,bsp,pet,bsp");
			level_10_rows.push_back("pvp,bsp,pel,php,php,php,php,pbr,bsp,pvp,gop");
			level_10_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,bsp,pvp,bsp");
			level_10_rows.push_back("pvp,bsp,pel,php,php,php,php,ptr,bsp,pvp,bsp");
			level_10_rows.push_back("pvp,bsp,bsp,bsp,bsp,bsp,bsp,pvp,bsp,peb,bsp");
			level_10_rows.push_back("pvp,bsp,pel,ptr,bsp,pet,bsp,pvp,bsp,bsp,bsp");
			level_10_rows.push_back("peb,bsp,spp,peb,spp,peb,spp,pbl,php,php,per");
		}

		switch (levelIndex)
		{
		case 0:
			return level_1_rows;
		case 1:
			return level_2_rows;
		case 2:
			return level_3_rows;
		case 3:
			return level_4_rows;
		case 4:
			return level_5_rows;
		case 5:
			return level_6_rows;
		case 6:
			return level_7_rows;
		case 7:
			return level_8_rows;
		case 8:
			return level_9_rows;
		default:
			return level_10_rows;
		}
	}

	// r = red creep
	// b = blue creep
	// g = green creep
	// y = yellow creep
	// 1 = creep type one
	// 2 = creep type two
	// 3 = creep type three
	// xn = boss creep normal color
	static std::vector<std::string> getWavesForLevelIndexAndSpawnPointIndex(int levelIndex, int spawnPointIndex)
	{
		static std::vector<std::string> waves_level_1;
		static std::vector<std::string> waves_level_2;
		static std::vector<std::string> waves_level_3_sp_0;
		static std::vector<std::string> waves_level_3_sp_1;
		static std::vector<std::string> waves_level_4;
		static std::vector<std::string> waves_level_5_sp_0;
		static std::vector<std::string> waves_level_5_sp_1;
		static std::vector<std::string> waves_level_6_sp_0;
		static std::vector<std::string> waves_level_6_sp_1;
		static std::vector<std::string> waves_level_6_sp_2;
		static std::vector<std::string> waves_level_6_sp_3;
		static std::vector<std::string> waves_level_6_sp_4;
		static std::vector<std::string> waves_level_7;
		static std::vector<std::string> waves_level_8_sp_0;
		static std::vector<std::string> waves_level_8_sp_1;
		static std::vector<std::string> waves_level_8_sp_2;
		static std::vector<std::string> waves_level_8_sp_3;
		static std::vector<std::string> waves_level_8_sp_4;
		static std::vector<std::string> waves_level_9_sp_0;
		static std::vector<std::string> waves_level_9_sp_1;
		static std::vector<std::string> waves_level_10_sp_0;
		static std::vector<std::string> waves_level_10_sp_1;
		static std::vector<std::string> waves_level_10_sp_2;
		static std::vector<std::string> waves_level_10_sp_3;
		static std::vector<std::string> waves_level_10_sp_4;
		static std::vector<std::string> waves_level_10_sp_5;

		if (waves_level_1.size() == 0)
		{
			waves_level_1.push_back("b1,b1");
			waves_level_1.push_back("b1,b1,b1,b1");
			waves_level_1.push_back("b1,b1,b1,b1,b1,b1,b1,b1");
			waves_level_1.push_back("b1,b1,b1,b1,b1,b1,b1,b1,b1,b1");
			waves_level_1.push_back("b1,b1,b1,b1,b1,b1,b1,b1,b2,b2");
			waves_level_1.push_back("b2,b2,b1,b1,b1,b1,b1,b1,b2,b2");
			waves_level_1.push_back("b2,b2,b1,b2,b1,b2,b1,b1,b2,b1");
			waves_level_1.push_back("b2,b2,b2,b2,b1,b2,b1,b1,b2,b1");
			waves_level_1.push_back("b2,b2,b2,b2,b2,b2,b2,b2,b2,b2");
			waves_level_1.push_back("xn");
			waves_level_1.push_back("b3,b3");
			waves_level_1.push_back("b3,b3,b2,b2");
			waves_level_1.push_back("b3,b3,b1,b1,b2,b2,b1,b1");
			waves_level_1.push_back("b3,b3,b2,b2,b1,b1,b2,b1,b3,b3");
			waves_level_1.push_back("b2,b2,b2,b2,b3,b3,b3,b3,b2,b2");
			waves_level_1.push_back("b1,b3,b1,b3,b1,b3,b1,b3,b1,b3");
			waves_level_1.push_back("b2,b3,b2,b3,b2,b3,b2,b3,b2,b3");
			waves_level_1.push_back("b3,b3,b2,b2,b3,b3,b3,b3,b3,b2");
			waves_level_1.push_back("b3,b3,b3,b3,b3,b3,b3,b3,b3,b3");
			waves_level_1.push_back("xn");

			waves_level_2.push_back("b1,b1,b1,b1,b1,b1,b1,b1,b1,b1");
			waves_level_2.push_back("b1,b1,b1,b1,b1,b1,b1,b1,r1,r1");
			waves_level_2.push_back("r1,r1,b1,b1,b1,b1,b1,b1,r1,r1");
			waves_level_2.push_back("r1,r1,b1,r1,b1,r1,b1,b1,r1,b1");
			waves_level_2.push_back("r1,r1,r1,r1,b1,r1,b1,b1,r1,b1");
			waves_level_2.push_back("r1,r1,r1,r1,r1,r1,r1,r1,r1,r1");
			waves_level_2.push_back("r1,r1,r1,r1,r1,b2,r1,b2,r1,b2");
			waves_level_2.push_back("r1,r1,r1,r1,r1,b2,r1,b2,r1,b2");
			waves_level_2.push_back("b2,b2,r1,r1,r1,b2,r1,b2,r1,b2");
			waves_level_2.push_back("xn");
			waves_level_2.push_back("b2,b2,b2,b2,b2,b2,b2,b2,b2,b2");
			waves_level_2.push_back("r1,r1,r1,b2,b2,b2,b2,b2,r2,r2");
			waves_level_2.push_back("r2,r1,r1,r1,r2,b2,b2,b2,r2,r2");
			waves_level_2.push_back("r2,r2,r2,r1,r1,b2,b2,b2,b2,b2");
			waves_level_2.push_back("r2,r1,r2,r1,r2,r1,r2,r1,r2,r1");
			waves_level_2.push_back("b2,b2,b2,b2,b2,b2,b2,r2,r2,r2");
			waves_level_2.push_back("r2,b2,r2,b2,r2,b2,r2,b2,r2,b2");
			waves_level_2.push_back("r2,r2,r2,r2,r2,r2,r2,r2,b2,b2");
			waves_level_2.push_back("r2,r2,r2,r2,r2,r2,r2,r2,r2,r2");
			waves_level_2.push_back("xn");
			waves_level_2.push_back("b3,b3,b3,b3,b3,b3,b3,b3,b3,b3");
			waves_level_2.push_back("r2,r2,r2,b3,b3,b3,b3,b3,r3,r3");
			waves_level_2.push_back("r3,r2,r2,r2,r3,b3,b3,b3,r3,r3");
			waves_level_2.push_back("r3,r3,r3,r2,r2,b3,b3,b3,b3,b3");
			waves_level_2.push_back("r3,r2,r3,r2,r3,r2,r3,r2,r3,r2");
			waves_level_2.push_back("b3,b3,b3,b3,b3,b3,b3,r3,r3,r3");
			waves_level_2.push_back("r3,b3,r3,b3,r3,b3,r3,b3,r3,b3");
			waves_level_2.push_back("r3,r3,r3,r3,r3,r3,r3,r3,b3,b3");
			waves_level_2.push_back("r3,r3,r3,r3,r3,r3,r3,r3,r3,r3");
			waves_level_2.push_back("xn");

			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g1,g1");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2");
			waves_level_3_sp_0.push_back("g2,g2");
			waves_level_3_sp_0.push_back("g2,g2");
			waves_level_3_sp_0.push_back("g2,g2");
			waves_level_3_sp_0.push_back("g3,g2");
			waves_level_3_sp_0.push_back("g3,g3");

			waves_level_3_sp_1.push_back("b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1,r1");
			waves_level_3_sp_1.push_back("xn");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b1,r2");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r1,b2,r2");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b1,r2,b2,r2");
			waves_level_3_sp_1.push_back("b1,r1,b1,r1,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("b1,r1,b1,r2,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("b1,r1,b2,r2,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r2,b2,r2");
			waves_level_3_sp_1.push_back("xn");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r2,b2,r3");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r2,b3,r3");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b2,r3,b3,r3");
			waves_level_3_sp_1.push_back("b2,r2,b2,r2,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("b2,r2,b2,r3,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("b2,r2,b3,r3,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("b3,r3,b3,r3,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("b3,r3,b3,r3,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("b3,r3,b3,r3,b3,r3,b3,r3");
			waves_level_3_sp_1.push_back("xn");

			waves_level_4.push_back("b1,b1,b1,b1,b1,b1,b1,b1,b1,b1");
			waves_level_4.push_back("b1,b1,b1,b1,b1,b1,b1,b1,b2,b2");
			waves_level_4.push_back("b2,b2,b1,b1,b1,b1,b1,b1,b2,b2");
			waves_level_4.push_back("b2,b2,b1,b2,b1,b2,b1,b1,b2,b1");
			waves_level_4.push_back("b2,b2,b2,b2,b1,b2,b1,b1,b2,b1");
			waves_level_4.push_back("b2,b2,b2,b2,b2,b2,b2,b2,b2,b2");
			waves_level_4.push_back("b3,b3,b2,b2,b1,b1,b2,b1,b3,b3");
			waves_level_4.push_back("b2,b2,b2,b2,b3,b3,b3,b3,b2,b2");
			waves_level_4.push_back("b3,b3,b3,b3,b3,b3,b3,b3,b3,b3");
			waves_level_4.push_back("xn");
			waves_level_4.push_back("r1,r1,r1,r1,r1,r1,r1,r1,r1,r1");
			waves_level_4.push_back("r1,r1,r1,r1,r1,r1,r1,r1,r2,r2");
			waves_level_4.push_back("r2,r2,r1,r1,r1,r1,r1,r1,r2,r2");
			waves_level_4.push_back("r2,r2,r1,r2,r1,r2,r1,r1,r2,r1");
			waves_level_4.push_back("r2,r2,r2,r2,r1,r2,r1,r1,r2,r1");
			waves_level_4.push_back("r2,r2,r2,r2,r2,r2,r2,r2,r2,r2");
			waves_level_4.push_back("r3,r3,r2,r2,r1,r1,r2,r1,r3,r3");
			waves_level_4.push_back("r2,r2,r2,r2,r3,r3,r3,r3,r2,r2");
			waves_level_4.push_back("r3,r3,r3,r3,r3,r3,r3,r3,r3,r3");
			waves_level_4.push_back("xn");
			waves_level_4.push_back("g1,g1,g1,g1,g1,g1,g1,g1,g1,g1");
			waves_level_4.push_back("g1,g1,g1,g1,g1,g1,g1,g1,g2,g2");
			waves_level_4.push_back("g2,g2,g1,g1,g1,g1,g1,g1,g2,g2");
			waves_level_4.push_back("g2,g2,g1,g2,g1,g2,g1,g1,g2,g1");
			waves_level_4.push_back("g2,g2,g2,g2,g1,g2,g1,g1,g2,g1");
			waves_level_4.push_back("g2,g2,g2,g2,g2,g2,g2,g2,g2,g2");
			waves_level_4.push_back("g3,g3,g2,g2,g1,g1,g2,g1,g3,g3");
			waves_level_4.push_back("g2,g2,g2,g2,g3,g3,g3,g3,g2,g2");
			waves_level_4.push_back("g3,g3,g3,g3,g3,g3,g3,g3,g3,g3");
			waves_level_4.push_back("xn");

			waves_level_5_sp_0.push_back("r1,r1,r1,r1,r1,r1");
			waves_level_5_sp_0.push_back("r1,r1,r1,r1,r1,r2");
			waves_level_5_sp_0.push_back("r1,r1,r1,r1,r1,r2");
			waves_level_5_sp_0.push_back("r2,r1,r1,r1,r1,r2");
			waves_level_5_sp_0.push_back("r2,r1,r1,r1,r1,r2");
			waves_level_5_sp_0.push_back("r2,r1,r2,r1,r1,r2");
			waves_level_5_sp_0.push_back("r2,r1,r2,r1,r1,r2");
			waves_level_5_sp_0.push_back("r2,r1,r2,r1,r2,r2");
			waves_level_5_sp_0.push_back("r2,r2,r2,r2,r2,r2");
			waves_level_5_sp_0.push_back("xn");
			waves_level_5_sp_0.push_back("r2,r2,r2,r2,r2,r2");
			waves_level_5_sp_0.push_back("r2,r2,r2,r2,r2,r3");
			waves_level_5_sp_0.push_back("r2,r2,r2,r2,r2,r3");
			waves_level_5_sp_0.push_back("r3,r2,r2,r2,r2,r3");
			waves_level_5_sp_0.push_back("r3,r2,r2,r2,r2,r3");
			waves_level_5_sp_0.push_back("r3,r2,r3,r2,r2,r3");
			waves_level_5_sp_0.push_back("r3,r2,r3,r2,r2,r3");
			waves_level_5_sp_0.push_back("r3,r2,r3,r2,r3,r3");
			waves_level_5_sp_0.push_back("r3,r3,r3,r3,r3,r3");
			waves_level_5_sp_0.push_back("xn");

			waves_level_5_sp_1.push_back("b1,b1,b1,b1,g1,g1");
			waves_level_5_sp_1.push_back("b1,b1,b1,b1,g1,g1");
			waves_level_5_sp_1.push_back("b1,b1,b1,b2,g1,g1");
			waves_level_5_sp_1.push_back("b1,b1,b1,b2,g1,g1");
			waves_level_5_sp_1.push_back("b2,b1,b1,b2,g1,g1");
			waves_level_5_sp_1.push_back("b2,b1,b1,b2,g1,g1");
			waves_level_5_sp_1.push_back("b2,b1,b2,b2,g1,g1");
			waves_level_5_sp_1.push_back("b2,b2,b2,b2,g2,g1");
			waves_level_5_sp_1.push_back("b2,b2,b2,b2,g2,g2");
			waves_level_5_sp_1.push_back("g2");
			waves_level_5_sp_1.push_back("b2,b2,b2,b2,g2,g2");
			waves_level_5_sp_1.push_back("b2,b2,b2,b2,g2,g2");
			waves_level_5_sp_1.push_back("b2,b2,b2,b3,g2,g2");
			waves_level_5_sp_1.push_back("b2,b2,b2,b3,g2,g2");
			waves_level_5_sp_1.push_back("b3,b2,b2,b3,g2,g2");
			waves_level_5_sp_1.push_back("b3,b2,b2,b3,g2,g2");
			waves_level_5_sp_1.push_back("b3,b2,b3,b3,g2,g2");
			waves_level_5_sp_1.push_back("b3,b3,b3,b3,g3,g2");
			waves_level_5_sp_1.push_back("b3,b3,b3,b3,g3,g3");
			waves_level_5_sp_1.push_back("g3");

			waves_level_6_sp_0.push_back("r1,r1,r1");
			waves_level_6_sp_0.push_back("r1,r1,r1");
			waves_level_6_sp_0.push_back("r1,r1,r2");
			waves_level_6_sp_0.push_back("r1,r1,r2");
			waves_level_6_sp_0.push_back("r1,r1,r2");
			waves_level_6_sp_0.push_back("r1,r1,r2");
			waves_level_6_sp_0.push_back("r1,r2,r2");
			waves_level_6_sp_0.push_back("r1,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r1");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r2");
			waves_level_6_sp_0.push_back("r2,r2,r3");
			waves_level_6_sp_0.push_back("r2,r2,r3");
			waves_level_6_sp_0.push_back("r2,r2,r3");
			waves_level_6_sp_0.push_back("g1");
			waves_level_6_sp_0.push_back("r2,r2,r3");
			waves_level_6_sp_0.push_back("r2,r3,r3");
			waves_level_6_sp_0.push_back("r2,r3,r3");
			waves_level_6_sp_0.push_back("r2,r3,r3");
			waves_level_6_sp_0.push_back("r2,r3,r3");
			waves_level_6_sp_0.push_back("r3,r3,r3");
			waves_level_6_sp_0.push_back("r3,r3,r3");
			waves_level_6_sp_0.push_back("r3,r3,r3");
			waves_level_6_sp_0.push_back("r3,r3,r3");
			waves_level_6_sp_0.push_back("r3");

			waves_level_6_sp_1.push_back("r1,r1");
			waves_level_6_sp_1.push_back("r1,r1");
			waves_level_6_sp_1.push_back("r1,r1");
			waves_level_6_sp_1.push_back("r1,r1");
			waves_level_6_sp_1.push_back("r1,r2");
			waves_level_6_sp_1.push_back("r1,r2");
			waves_level_6_sp_1.push_back("r1,r2");
			waves_level_6_sp_1.push_back("r1,r2");
			waves_level_6_sp_1.push_back("r1,r2");
			waves_level_6_sp_1.push_back("r1");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r2");
			waves_level_6_sp_1.push_back("r2,r3");
			waves_level_6_sp_1.push_back("g1");
			waves_level_6_sp_1.push_back("r2,r3");
			waves_level_6_sp_1.push_back("r2,r3");
			waves_level_6_sp_1.push_back("r2,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("r3,r3");
			waves_level_6_sp_1.push_back("g2");

			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("xn");
			waves_level_6_sp_2.push_back("g1,g1,g1,g1");
			waves_level_6_sp_2.push_back("g1,g1,g1,g2");
			waves_level_6_sp_2.push_back("g1,g1,g2,g2");
			waves_level_6_sp_2.push_back("g1,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("xn");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g2");
			waves_level_6_sp_2.push_back("g2,g2,g2,g3");
			waves_level_6_sp_2.push_back("g2,g2,g3,g3");
			waves_level_6_sp_2.push_back("g3,g3,g3,g3");
			waves_level_6_sp_2.push_back("xn");

			waves_level_6_sp_3.push_back("b1,b1");
			waves_level_6_sp_3.push_back("b1,b1");
			waves_level_6_sp_3.push_back("b1,b1");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1,b2");
			waves_level_6_sp_3.push_back("b1");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b2");
			waves_level_6_sp_3.push_back("b2,b3");
			waves_level_6_sp_3.push_back("b2,b3");
			waves_level_6_sp_3.push_back("g1");
			waves_level_6_sp_3.push_back("b2,b3");
			waves_level_6_sp_3.push_back("b2,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("b3,b3");
			waves_level_6_sp_3.push_back("g2");

			waves_level_6_sp_4.push_back("b1,b1,b1");
			waves_level_6_sp_4.push_back("b1,b1,b2");
			waves_level_6_sp_4.push_back("b1,b1,b2");
			waves_level_6_sp_4.push_back("b1,b1,b2");
			waves_level_6_sp_4.push_back("b1,b1,b2");
			waves_level_6_sp_4.push_back("b1,b2,b2");
			waves_level_6_sp_4.push_back("b1,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b1");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b2");
			waves_level_6_sp_4.push_back("b2,b2,b3");
			waves_level_6_sp_4.push_back("b2,b2,b3");
			waves_level_6_sp_4.push_back("b2,b2,b3");
			waves_level_6_sp_4.push_back("b2,b2,b3");
			waves_level_6_sp_4.push_back("g1");
			waves_level_6_sp_4.push_back("b2,b3,b3");
			waves_level_6_sp_4.push_back("b2,b3,b3");
			waves_level_6_sp_4.push_back("b2,b3,b3");
			waves_level_6_sp_4.push_back("b2,b3,b3");
			waves_level_6_sp_4.push_back("b3,b3,b3");
			waves_level_6_sp_4.push_back("b3,b3,b3");
			waves_level_6_sp_4.push_back("b3,b3,b3");
			waves_level_6_sp_4.push_back("b3,b3,b3");
			waves_level_6_sp_4.push_back("b3,b3,b3");
			waves_level_6_sp_4.push_back("b3");

			waves_level_7.push_back("y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1");
			waves_level_7.push_back("y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y2");
			waves_level_7.push_back("y2,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y2");
			waves_level_7.push_back("y2,y1,y2,y1,y1,y1,y1,y1,y1,y1,y1,y1,y1,y2,y1,y2");
			waves_level_7.push_back("y2,y1,y2,y1,y2,y1,y1,y1,y1,y1,y1,y2,y1,y2,y1,y2");
			waves_level_7.push_back("y2,y1,y2,y1,y2,y1,y2,y1,y1,y2,y1,y2,y1,y2,y1,y2");
			waves_level_7.push_back("y2,y1,y2,y1,y2,y1,y2,y1,y1,y2,y1,y2,y1,y2,y1,y2");
			waves_level_7.push_back("y2,y2,y2,y1,y2,y1,y2,y1,y1,y2,y1,y2,y1,y2,y2,y2");
			waves_level_7.push_back("y2,y2,y2,y1,y2,y1,y2,y1,y1,y2,y1,y2,y1,y2,y2,y2");
			waves_level_7.push_back("xn");
			waves_level_7.push_back("y2,y2,y2,y2,y2,y1,y2,y1,y1,y2,y1,y2,y2,y2,y2,y2");
			waves_level_7.push_back("y2,y2,y2,y2,y2,y2,y2,y1,y1,y2,y2,y2,y2,y2,y2,y2");
			waves_level_7.push_back("y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2");
			waves_level_7.push_back("y3,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y3");
			waves_level_7.push_back("y3,y2,y3,y2,y2,y2,y2,y2,y2,y2,y2,y2,y2,y3,y2,y3");
			waves_level_7.push_back("y3,y2,y3,y2,y3,y2,y2,y2,y2,y2,y2,y3,y2,y3,y2,y3");
			waves_level_7.push_back("y3,y2,y3,y2,y3,y2,y3,y2,y2,y3,y2,y3,y2,y3,y2,y3");
			waves_level_7.push_back("y3,y2,y3,y2,y3,y2,y3,y3,y3,y3,y2,y3,y2,y3,y2,y3");
			waves_level_7.push_back("y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3,y3");
			waves_level_7.push_back("xn");

			waves_level_8_sp_0.push_back("r1,r1");
			waves_level_8_sp_0.push_back("r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1,r1");
			waves_level_8_sp_0.push_back("r1,r1,r1,r1");
			waves_level_8_sp_0.push_back("r1");
			waves_level_8_sp_0.push_back("r1,r1,r1,r2");
			waves_level_8_sp_0.push_back("r1,r1,r1,r2");
			waves_level_8_sp_0.push_back("r1,r1,r1,r2");
			waves_level_8_sp_0.push_back("r1,r1,r2,r2");
			waves_level_8_sp_0.push_back("r1,r1,r2,r2");
			waves_level_8_sp_0.push_back("r1,r1,r2,r2");
			waves_level_8_sp_0.push_back("r1,r2,r2,r2");
			waves_level_8_sp_0.push_back("r1,r2,r2,r2");
			waves_level_8_sp_0.push_back("r1,r2,r2,r2");
			waves_level_8_sp_0.push_back("r1");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r2");
			waves_level_8_sp_0.push_back("r2");
			waves_level_8_sp_0.push_back("r2,r2,r2,r3");
			waves_level_8_sp_0.push_back("r2,r2,r2,r3");
			waves_level_8_sp_0.push_back("r2,r2,r2,r3");
			waves_level_8_sp_0.push_back("r2,r2,r3,r3");
			waves_level_8_sp_0.push_back("r2,r2,r3,r3");
			waves_level_8_sp_0.push_back("r2,r2,r3,r3");
			waves_level_8_sp_0.push_back("r2,r3,r3,r3");
			waves_level_8_sp_0.push_back("r2,r3,r3,r3");
			waves_level_8_sp_0.push_back("r2,r3,r3,r3");
			waves_level_8_sp_0.push_back("r2");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r3,r3,r3,r3");
			waves_level_8_sp_0.push_back("r2");

			waves_level_8_sp_1.push_back("g1");
			waves_level_8_sp_1.push_back("g1");
			waves_level_8_sp_1.push_back("g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("r1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g1");
			waves_level_8_sp_1.push_back("g1,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g1");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g2");
			waves_level_8_sp_1.push_back("g2,g3");
			waves_level_8_sp_1.push_back("g3,g3");
			waves_level_8_sp_1.push_back("g2");

			waves_level_8_sp_2.push_back("y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("xn");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y1");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y2");
			waves_level_8_sp_2.push_back("xn");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y2");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y1,y2");
			waves_level_8_sp_2.push_back("y1,y1,y1,y1,y2,y2");
			waves_level_8_sp_2.push_back("y1,y1,y1,y2,y2,y2");
			waves_level_8_sp_2.push_back("y1,y1,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y1,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("xn");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y2");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y3");
			waves_level_8_sp_2.push_back("xn");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y3");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y2,y3");
			waves_level_8_sp_2.push_back("y2,y2,y2,y2,y3,y3");
			waves_level_8_sp_2.push_back("y2,y2,y2,y3,y3,y3");
			waves_level_8_sp_2.push_back("y2,y2,y3,y3,y3,y3");
			waves_level_8_sp_2.push_back("y2,y3,y3,y3,y3,y3");
			waves_level_8_sp_2.push_back("y3,y3,y3,y3,y3,y3");
			waves_level_8_sp_2.push_back("y3,y3,y3,y3,y3,y3");
			waves_level_8_sp_2.push_back("y3,y3,y3,y3,y3,y3");
			waves_level_8_sp_2.push_back("xn,xn");

			waves_level_8_sp_3.push_back("b1,b1");
			waves_level_8_sp_3.push_back("b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1,b1");
			waves_level_8_sp_3.push_back("b1");
			waves_level_8_sp_3.push_back("b1,b1,b1,b1");
			waves_level_8_sp_3.push_back("b1,b1,b1,b2");
			waves_level_8_sp_3.push_back("b1,b1,b1,b2");
			waves_level_8_sp_3.push_back("b1,b1,b1,b2");
			waves_level_8_sp_3.push_back("b1,b1,b2,b2");
			waves_level_8_sp_3.push_back("b1,b1,b2,b2");
			waves_level_8_sp_3.push_back("b1,b1,b2,b2");
			waves_level_8_sp_3.push_back("b1,b2,b2,b2");
			waves_level_8_sp_3.push_back("b1,b2,b2,b2");
			waves_level_8_sp_3.push_back("b1");
			waves_level_8_sp_3.push_back("b1,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b2");
			waves_level_8_sp_3.push_back("b2,b2,b2,b3");
			waves_level_8_sp_3.push_back("b2,b2,b2,b3");
			waves_level_8_sp_3.push_back("b2,b2,b2,b3");
			waves_level_8_sp_3.push_back("b2,b2,b3,b3");
			waves_level_8_sp_3.push_back("b2,b2,b3,b3");
			waves_level_8_sp_3.push_back("b2,b2,b3,b3");
			waves_level_8_sp_3.push_back("b2,b3,b3,b3");
			waves_level_8_sp_3.push_back("b2,b3,b3,b3");
			waves_level_8_sp_3.push_back("b2");
			waves_level_8_sp_3.push_back("b2,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b3,b3,b3,b3");
			waves_level_8_sp_3.push_back("b2");

			waves_level_8_sp_4.push_back("g1");
			waves_level_8_sp_4.push_back("g1");
			waves_level_8_sp_4.push_back("g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("b1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g1");
			waves_level_8_sp_4.push_back("g1,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g1");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g2");
			waves_level_8_sp_4.push_back("g2,g3");
			waves_level_8_sp_4.push_back("g3,g3");
			waves_level_8_sp_4.push_back("g2");

			waves_level_9_sp_0.push_back("b1,b1,b1,b1,b1");
			waves_level_9_sp_0.push_back("b1,b1,b1,b1,b2");
			waves_level_9_sp_0.push_back("b1,b1,b1,b1,b2");
			waves_level_9_sp_0.push_back("b1,b1,b1,b2,b2");
			waves_level_9_sp_0.push_back("b1,b1,b1,b2,b2");
			waves_level_9_sp_0.push_back("b1,b1,b2,b2,b2");
			waves_level_9_sp_0.push_back("b1,b1,b2,b2,b2");
			waves_level_9_sp_0.push_back("b1,b2,b2,b2,b2");
			waves_level_9_sp_0.push_back("b1,b2,b2,b2,b2");
			waves_level_9_sp_0.push_back("b3");
			waves_level_9_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_9_sp_0.push_back("b2,b2,b2,b2,b3");
			waves_level_9_sp_0.push_back("b2,b2,b2,b3,b3");
			waves_level_9_sp_0.push_back("b2,b2,b2,b3,b3");
			waves_level_9_sp_0.push_back("b2,b2,b3,b3,b3");
			waves_level_9_sp_0.push_back("b2,b2,b3,b3,b3");
			waves_level_9_sp_0.push_back("b2,b3,b3,b3,b3");
			waves_level_9_sp_0.push_back("b2,b3,b3,b3,b3");
			waves_level_9_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_9_sp_0.push_back("xn");
			waves_level_9_sp_0.push_back("g1,g1,g1,g1,g1");
			waves_level_9_sp_0.push_back("g1,g1,g1,g1,g2");
			waves_level_9_sp_0.push_back("g1,g1,g1,g1,g2");
			waves_level_9_sp_0.push_back("g1,g1,g1,g2,g2");
			waves_level_9_sp_0.push_back("g1,g1,g1,g2,g2");
			waves_level_9_sp_0.push_back("g1,g1,g2,g2,g2");
			waves_level_9_sp_0.push_back("g1,g1,g2,g2,g2");
			waves_level_9_sp_0.push_back("g1,g2,g2,g2,g2");
			waves_level_9_sp_0.push_back("g1,g2,g2,g2,g2");
			waves_level_9_sp_0.push_back("g3");
			waves_level_9_sp_0.push_back("g2,g2,g2,g2,g2");
			waves_level_9_sp_0.push_back("g2,g2,g2,g2,g3");
			waves_level_9_sp_0.push_back("g2,g2,g2,g3,g3");
			waves_level_9_sp_0.push_back("g2,g2,g2,g3,g3");
			waves_level_9_sp_0.push_back("g2,g2,g3,g3,g3");
			waves_level_9_sp_0.push_back("g2,g2,g3,g3,g3");
			waves_level_9_sp_0.push_back("g2,g3,g3,g3,g3");
			waves_level_9_sp_0.push_back("g2,g3,g3,g3,g3");
			waves_level_9_sp_0.push_back("g3,g3,g3,g3,g3");
			waves_level_9_sp_0.push_back("xn");

			waves_level_9_sp_1.push_back("r1,r1,r1,r1,r1");
			waves_level_9_sp_1.push_back("r1,r1,r1,r1,r1");
			waves_level_9_sp_1.push_back("r1,r1,r1,r1,r2");
			waves_level_9_sp_1.push_back("r1,r1,r1,r1,r2");
			waves_level_9_sp_1.push_back("r1,r1,r1,r2,r2");
			waves_level_9_sp_1.push_back("r1,r1,r1,r2,r2");
			waves_level_9_sp_1.push_back("r1,r1,r2,r2,r2");
			waves_level_9_sp_1.push_back("r1,r1,r2,r2,r2");
			waves_level_9_sp_1.push_back("r1,r2,r2,r2,r2");
			waves_level_9_sp_1.push_back("xn");
			waves_level_9_sp_1.push_back("r2,r2,r2,r2,r2");
			waves_level_9_sp_1.push_back("r2,r2,r2,r2,r3");
			waves_level_9_sp_1.push_back("r2,r2,r2,r2,r3");
			waves_level_9_sp_1.push_back("r2,r2,r2,r3,r3");
			waves_level_9_sp_1.push_back("r2,r2,r2,r3,r3");
			waves_level_9_sp_1.push_back("r2,r2,r3,r3,r3");
			waves_level_9_sp_1.push_back("r2,r2,r3,r3,r3");
			waves_level_9_sp_1.push_back("r2,r3,r3,r3,r3");
			waves_level_9_sp_1.push_back("r3,r3,r3,r3,r3");
			waves_level_9_sp_1.push_back("r3");
			waves_level_9_sp_1.push_back("y1,y1,y1,y1,y1");
			waves_level_9_sp_1.push_back("y1,y1,y1,y1,y1");
			waves_level_9_sp_1.push_back("y1,y1,y1,y1,y2");
			waves_level_9_sp_1.push_back("y1,y1,y1,y1,y2");
			waves_level_9_sp_1.push_back("y1,y1,y1,y2,y2");
			waves_level_9_sp_1.push_back("y1,y1,y1,y2,y2");
			waves_level_9_sp_1.push_back("y1,y1,y2,y2,y2");
			waves_level_9_sp_1.push_back("y1,y1,y2,y2,y2");
			waves_level_9_sp_1.push_back("y1,y2,y2,y2,y2");
			waves_level_9_sp_1.push_back("xn");
			waves_level_9_sp_1.push_back("y2,y2,y2,y2,y2");
			waves_level_9_sp_1.push_back("y2,y2,y2,y2,y3");
			waves_level_9_sp_1.push_back("y2,y2,y2,y2,y3");
			waves_level_9_sp_1.push_back("y2,y2,y2,y3,y3");
			waves_level_9_sp_1.push_back("y2,y2,y2,y3,y3");
			waves_level_9_sp_1.push_back("y2,y2,y3,y3,y3");
			waves_level_9_sp_1.push_back("y2,y2,y3,y3,y3");
			waves_level_9_sp_1.push_back("y2,y3,y3,y3,y3");
			waves_level_9_sp_1.push_back("y3,y3,y3,y3,y3");
			waves_level_9_sp_1.push_back("y3");

			waves_level_10_sp_0.push_back("b1");
			waves_level_10_sp_0.push_back("b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("xn");
			waves_level_10_sp_0.push_back("b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("xn");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1,b1");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1,b2");
			waves_level_10_sp_0.push_back("b1,b1,b1,b1,b2");
			waves_level_10_sp_0.push_back("b1,b1,b1,b2,b2");
			waves_level_10_sp_0.push_back("b1,b1,b1,b2,b2");
			waves_level_10_sp_0.push_back("b1,b1,b2,b2,b2");
			waves_level_10_sp_0.push_back("b1,b1,b2,b2,b2");
			waves_level_10_sp_0.push_back("xn");
			waves_level_10_sp_0.push_back("b1,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b1,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("xn");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b2");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b3");
			waves_level_10_sp_0.push_back("b2,b2,b2,b2,b3");
			waves_level_10_sp_0.push_back("b2,b2,b2,b3,b3");
			waves_level_10_sp_0.push_back("b2,b2,b2,b3,b3");
			waves_level_10_sp_0.push_back("b2,b2,b3,b3,b3");
			waves_level_10_sp_0.push_back("b2,b2,b3,b3,b3");
			waves_level_10_sp_0.push_back("b2,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b2,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("xn");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("b3,b3,b3,b3,b3");
			waves_level_10_sp_0.push_back("xn");

			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("xn");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g1");
			waves_level_10_sp_1.push_back("g1,g1,g2");
			waves_level_10_sp_1.push_back("g1,g1,g2");
			waves_level_10_sp_1.push_back("g1,g1,g2");
			waves_level_10_sp_1.push_back("g1,g1,g2");
			waves_level_10_sp_1.push_back("g1,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("xn");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("xn");
			waves_level_10_sp_1.push_back("g2,g2,g2");
			waves_level_10_sp_1.push_back("g2,g2,g3");
			waves_level_10_sp_1.push_back("g2,g2,g3");
			waves_level_10_sp_1.push_back("g2,g2,g3");
			waves_level_10_sp_1.push_back("g2,g2,g3");
			waves_level_10_sp_1.push_back("g2,g3,g3");
			waves_level_10_sp_1.push_back("g2,g3,g3");
			waves_level_10_sp_1.push_back("g3,g3,g3");
			waves_level_10_sp_1.push_back("g3,g3,g3");
			waves_level_10_sp_1.push_back("xn");

			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y1");
			waves_level_10_sp_2.push_back("y1,y1,y2");
			waves_level_10_sp_2.push_back("y1,y1,y2");
			waves_level_10_sp_2.push_back("y1,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y1");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("xn");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y2");
			waves_level_10_sp_2.push_back("y2,y2,y3");
			waves_level_10_sp_2.push_back("y2,y2,y3");
			waves_level_10_sp_2.push_back("y2,y2,y3");
			waves_level_10_sp_2.push_back("y2,y3,y3");
			waves_level_10_sp_2.push_back("y2,y3,y3");
			waves_level_10_sp_2.push_back("y3,y3,y3");
			waves_level_10_sp_2.push_back("xn");

			waves_level_10_sp_3.push_back("r1");
			waves_level_10_sp_3.push_back("r1");
			waves_level_10_sp_3.push_back("r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("xn");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1,r1");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1,r2");
			waves_level_10_sp_3.push_back("r1,r1,r1,r1,r2");
			waves_level_10_sp_3.push_back("r1,r1,r1,r2,r2");
			waves_level_10_sp_3.push_back("r1,r1,r1,r2,r2");
			waves_level_10_sp_3.push_back("r1,r1,r2,r2,r2");
			waves_level_10_sp_3.push_back("xn");
			waves_level_10_sp_3.push_back("r1,r1,r2,r2,r2");
			waves_level_10_sp_3.push_back("r1,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("xn");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r2");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r3");
			waves_level_10_sp_3.push_back("r2,r2,r2,r2,r3");
			waves_level_10_sp_3.push_back("r2,r2,r2,r3,r3");
			waves_level_10_sp_3.push_back("r2,r2,r2,r3,r3");
			waves_level_10_sp_3.push_back("r2,r2,r3,r3,r3");
			waves_level_10_sp_3.push_back("r2,r2,r3,r3,r3");
			waves_level_10_sp_3.push_back("r2,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("xn");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("r3,r3,r3,r3,r3");
			waves_level_10_sp_3.push_back("xn");

			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g1");
			waves_level_10_sp_4.push_back("g1,g1,g2");
			waves_level_10_sp_4.push_back("g1,g1,g2");
			waves_level_10_sp_4.push_back("g1,g1,g2");
			waves_level_10_sp_4.push_back("g1,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("xn");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("xn");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g2");
			waves_level_10_sp_4.push_back("g2,g2,g3");
			waves_level_10_sp_4.push_back("g2,g2,g3");
			waves_level_10_sp_4.push_back("g2,g2,g3");
			waves_level_10_sp_4.push_back("g2,g3,g3");
			waves_level_10_sp_4.push_back("g2,g3,g3");
			waves_level_10_sp_4.push_back("g3,g3,g3");
			waves_level_10_sp_4.push_back("g3,g3,g3");
			waves_level_10_sp_4.push_back("xn");

			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y1");
			waves_level_10_sp_5.push_back("y1,y1,y2");
			waves_level_10_sp_5.push_back("y1,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y1");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y2");
			waves_level_10_sp_5.push_back("y2,y2,y3");
			waves_level_10_sp_5.push_back("y2,y2,y3");
			waves_level_10_sp_5.push_back("y2,y3,y3");
			waves_level_10_sp_5.push_back("y2,y3,y3");
			waves_level_10_sp_5.push_back("y3,y3,y3");
			waves_level_10_sp_5.push_back("xn");
		}

		switch (levelIndex)
		{
		case 0:
			return waves_level_1;
		case 1:
			return waves_level_2;
		case 2:
			return spawnPointIndex == 0 ? waves_level_3_sp_0 : waves_level_3_sp_1;
		case 3:
			return waves_level_4;
		case 4:
			return spawnPointIndex == 0 ? waves_level_5_sp_0 : waves_level_5_sp_1;
		case 5:
			switch (spawnPointIndex)
			{
			case 0:
				return waves_level_6_sp_0;
			case 1:
				return waves_level_6_sp_1;
			case 2:
				return waves_level_6_sp_2;
			case 3:
				return waves_level_6_sp_3;
			default:
				return waves_level_6_sp_4;
			}
		case 6:
			return waves_level_7;
		case 7:
			switch (spawnPointIndex)
			{
			case 0:
				return waves_level_8_sp_0;
			case 1:
				return waves_level_8_sp_1;
			case 2:
				return waves_level_8_sp_2;
			case 3:
				return waves_level_8_sp_3;
			default:
				return waves_level_8_sp_4;
			}
		case 8:
			return spawnPointIndex == 0 ? waves_level_9_sp_0 : waves_level_9_sp_1;
		default:
			switch (spawnPointIndex)
			{
			case 0:
				return waves_level_10_sp_0;
			case 1:
				return waves_level_10_sp_1;
			case 2:
				return waves_level_10_sp_2;
			case 3:
				return waves_level_10_sp_3;
			case 4:
				return waves_level_10_sp_4;
			default:
				return waves_level_10_sp_5;
			}
		}
	}
};

#endif /* defined(__insectoiddefense__LevelUtils__) */