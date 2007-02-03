const ExtractEntry kyra1FreFloppy[] = {
	{ kKallakWritingSeq, 0x00030598, 0x00030D8D },
	{ kMalcolmTreeSeq, 0x00030D8D, 0x00030FA3 },
	{ kWestwoodLogoSeq, 0x00030FA3, 0x00030FEE },
	{ kKyrandiaLogoSeq, 0x00030FEE, 0x0003104A },
	{ kKallakMalcolmSeq, 0x0003104A, 0x000312B5 },
	{ kForestSeq, 0x000312B5, 0x0003144A },
	{ kIntroCPSStrings, 0x0003144A, 0x0003145E },
	{ kIntroWSAStrings, 0x0003145E, 0x000314DE },
	{ kIntroCOLStrings, 0x000314DE, 0x00031509 },
	{ kIntroStrings, 0x00031509, 0x00031AF8 },
	{ kItemNames, 0x00034862, 0x00034d68 },
	{ kTakenStrings, 0x00034062, 0x00034080 },
	{ kPlacedStrings, 0x00034080, 0x00034091 },
	{ kDroppedStrings, 0x0003412f, 0x00034140 },
	{ kNoDropStrings, 0x00034016, 0x00034062 },
	{ kPutDownString, 0x0002f240, 0x0002f26e },
	{ kWaitAmuletString, 0x0002f26e, 0x0002f2b7 },
	{ kBlackJewelString, 0x0002f2b7, 0x0002f2e2 },
	{ kHealingTipString, 0x0002f2e2, 0x0002f318 },
	{ kPoisonGoneString, 0x0002f384, 0x0002f3dd },
	{ kThePoisonStrings, 0x0003000e, 0x00030076 },
	{ kFluteStrings, 0x000324af, 0x000324f4 },
	{ kWispJewelStrings, 0x0002f318, 0x0002f373 },
	{ kMagicJewelStrings, 0x0002f373, 0x0002f384 },
	{ kFlaskFullString, 0x0003011c, 0x0003013a },
	{ kFullFlaskString, 0x00030096, 0x0003011c },
	{ kOutroHomeString, 0x000321f4, 0x000321fb },
	{ kVeryCleverString, 0x0003215e, 0x00032185 },
	{ kGUIStrings, 0x0002f51c, 0x0002f750 },
	{ kNewGameString, 0x00032ca2, 0x00032cbf },
	{ kConfigStrings, 0x0002ff96, 0x0002ffe1 },
	{ -1, 0, 0 }
};

const ExtractEntry kyra1FreCD[] = {
	{ kKallakWritingSeq, 0x0003023D, 0x00030A42 },
	{ kMalcolmTreeSeq, 0x00030A42, 0x00030C72 },
	{ kWestwoodLogoSeq, 0x00030C72, 0x00030CBD },
	{ kKyrandiaLogoSeq, 0x00030CBD, 0x00030D63 },
	{ kKallakMalcolmSeq, 0x00030D63, 0x0003101B },
	{ kForestSeq, 0x0003101B, 0x0003128E },
	{ kIntroCPSStrings, 0x0003128E, 0x000312A3 },
	{ kIntroWSAStrings, 0x000312A3, 0x00031323 },
	{ kIntroCOLStrings, 0x00031323, 0x0003134E },
	{ kIntroStrings, 0x0003134E, 0x0003193E },
	{ kRoomList, 0x000283A0, 0x0002D176 },
	{ kRoomFilenames, 0x000342AA, 0x00034586 },
	{ kCharacterImageFilenames, 0x00033206, 0x000332EA },
	{ kDefaultShapes, 0x0002D330, 0x0002D823 },
	{ kItemNames, 0x000347C0, 0x00034CC6 },
	{ kTakenStrings, 0x0003427B, 0x0003428A },
	{ kPlacedStrings, 0x000341EA, 0x000341FB },
	{ kDroppedStrings, 0x00034299, 0x000342AA },
	{ kNoDropStrings, 0x00034180, 0x000341CC },
	{ kPutDownString, 0x0002F070, 0x0002F09E },
	{ kWaitAmuletString, 0x0002F09E, 0x0002F0E7 },
	{ kBlackJewelString, 0x0002F0E7, 0x0002F112 },
	{ kHealingTipString, 0x0002F112, 0x0002F148 },
	{ kPoisonGoneString, 0x0002F1A9, 0x0002F1D3 },
	{ kThePoisonStrings, 0x0002FE76, 0x0002FEDE },
	{ kFluteStrings, 0x000327EA, 0x0003282F },
	{ kWispJewelStrings, 0x0002F148, 0x0002F198 },
	{ kMagicJewelStrings, 0x0002F198, 0x0002F1A9 },
	{ kFlaskFullString, 0x0002FF8C, 0x0002FFAA },
	{ kFullFlaskString, 0x0002FF06, 0x0002FF8C },
	{ kOutroHomeString, 0x000320D6, 0x000320DD },
	{ kVeryCleverString, 0x00032038, 0x0003205F },
	{ kGUIStrings, 0x0002f32c, 0x0002f589 },
	{ kNewGameString, 0x00032FDF, 0x00032FFC },
	{ kConfigStrings, 0x0002fdcf, 0x0002fe49 },
	{ -1, 0, 0 }
};

const Game kyra1FreGames[] = {
	{ kKyra1, Common::FR_FRA, -1, "aa9d6d78d8b199deaf48efeca6d19af2", kyra1FreFloppy },
	{ kKyra1, Common::FR_FRA, kTalkieVersion, "307c5d4a554d9068ac3d326e350ae4a6", kyra1FreCD },
	GAME_DUMMY_ENTRY
};