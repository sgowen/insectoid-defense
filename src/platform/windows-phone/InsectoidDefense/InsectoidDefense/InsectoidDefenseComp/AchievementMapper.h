//
//  AchievementMapper.h
//  insectoid-defense
//
//  Created by Stephen Gowen on 2/5/14.
//  Copyright (c) 2014 Gowen Game Dev. All rights reserved.
//

#ifndef __insectoiddefense__AchievementMapper__
#define __insectoiddefense__AchievementMapper__

#include <string>

class AchievementMapper
{
public:
	static std::wstring GetIDForAchievement(int difficulty, int levelIndex, int wavesCompleted)
	{
		switch (levelIndex)
		{
		case 0:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"3b574d18-650e-47a0-95a2-1c6242d2ee4b" : difficulty == 1 ? L"9a1d0aeb-5ca3-4b54-8ee4-7ec9a84c2619" : L"739c904f-5b10-48f4-9ab9-95b928314acd";
			case 20:
				return difficulty == 0 ? L"3cd1c411-89d4-4ad8-9b0f-80946406fbe2" : difficulty == 1 ? L"8150ccbe-cbd3-4451-a5c9-bbb7c16f86ba" : L"ea5eea40-7cea-4d1e-88ea-689beb3d3840";
			case 30:
				return difficulty == 0 ? L"3c68e419-8e74-47fa-add1-3add18be1616" : difficulty == 1 ? L"50120ff4-0025-40c0-aba4-1d4d514ae6f6" : L"2b35e7b6-a198-4b5a-ba8e-315da5bae3c6";
			case 40:
				return difficulty == 0 ? L"0930025f-cabf-4e8b-b430-13a7fa6bf6f7" : difficulty == 1 ? L"b0b6516e-3059-4055-a67c-393e8c0e9f7d" : L"7cc2fa92-788b-4ad6-b6b6-36c8e7f4c0e6";
			default:
				return L"";
			}

		case 1:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"0c6d7b73-6ead-4bc1-949b-74a21c60c9bf" : difficulty == 1 ? L"50ff5851-d901-4736-bc42-2d8911b040b7" : L"65ac52d6-de37-4e18-86e7-3fe09aa15dde";
			case 20:
				return difficulty == 0 ? L"1e78541d-0d7d-4512-8f5f-617338cbb070" : difficulty == 1 ? L"c1577fbf-b40b-4702-9608-8d7f322c7170" : L"f35f989b-c68f-480d-b5ad-18141b0e2023";
			case 30:
				return difficulty == 0 ? L"2fd76386-2ab7-4812-8573-861f1ddaa1f5" : difficulty == 1 ? L"7d2d2365-842d-4480-8399-a910365c056b" : L"40f77d7b-d376-4fd2-98df-1f8304d3c158";
			case 40:
				return difficulty == 0 ? L"0c9e6944-00dd-4277-8c3f-86f414e4c45f" : difficulty == 1 ? L"be2caca0-b334-4553-b1ba-8cd92a4d8dfc" : L"d3f59943-3ca0-4d38-8687-4fd9de00946a";
			default:
				return L"";
			}

		case 2:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"76978f4e-256f-4333-81a2-58754389803f" : difficulty == 1 ? L"24724251-494a-492a-914d-cb026adf572a" : L"dcb3acb9-a1ab-4bf3-b549-d7c8385645d4";
			case 20:
				return difficulty == 0 ? L"5e8c3979-3701-4623-baba-29e921ad2c62" : difficulty == 1 ? L"e9635043-f050-46bf-aec7-560fedfb0eb6" : L"9ddc6af5-8019-4993-bf19-1d834d4ca5ea";
			case 30:
				return difficulty == 0 ? L"7637911d-4a8f-4d2f-87a6-cc0a60bb0e61" : difficulty == 1 ? L"939c947d-3c17-4b68-85c9-62fefbc9a95e" : L"26c58a86-0abb-40ba-93c1-87382be9feb9";
			case 40:
				return difficulty == 0 ? L"df40c616-9175-460a-9ff9-c64b53e20c4a" : difficulty == 1 ? L"179e546b-a7c1-4ae6-bb7b-491b2edcb524" : L"203af0b3-6c62-4731-875c-70ad138e9448";
			default:
				return L"";
			}

		case 3:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"73650cf5-2f17-4009-a6d7-4ba121d44d61" : difficulty == 1 ? L"6ec62a3a-232c-4d63-9fec-b77e84380890" : L"ae44bc4d-b27d-476f-a591-5c9d7e84d069";
			case 20:
				return difficulty == 0 ? L"490123ae-bb5e-40d8-8f9d-b82cd2ea174b" : difficulty == 1 ? L"c0c7a03a-455a-4faf-8137-1f2095c9736d" : L"a21ba85c-9c3d-4251-b484-e5cbab488556";
			case 30:
				return difficulty == 0 ? L"8465442a-cfd4-4017-96f1-bade6bd0a5b5" : difficulty == 1 ? L"38d35e96-d187-4575-802a-23ba84a1c065" : L"9e596a4e-32d6-4b5f-be9a-ed64499f273e";
			case 40:
				return difficulty == 0 ? L"69bea27e-1059-4a34-a989-e90a1e7128d3" : difficulty == 1 ? L"fc092d73-7dbd-4ca6-99e1-5b4ba1dd0a62" : L"4f7cba79-013b-4415-9fcc-099d0645921b";
			default:
				return L"";
			}

		case 4:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"1fc7ebdc-5add-4d63-a902-9a88574b9169" : difficulty == 1 ? L"5952fcb8-3a3f-4632-8e8a-f100e8d42b61" : L"2a950029-8a5d-4def-aa7c-f5192ccebaad";
			case 20:
				return difficulty == 0 ? L"659dcff0-4a05-4bb7-9a6a-e94b5be7f120" : difficulty == 1 ? L"339567d0-7139-417f-ae74-19ad5ebc1c77" : L"c93da0bd-4720-4ebf-9657-1fcc771eddcd";
			case 30:
				return difficulty == 0 ? L"7e30ab18-0eb4-4344-83b4-043df34747f0" : difficulty == 1 ? L"0164be70-d7ac-4c79-9ef3-80408e2e351c" : L"eb7a0716-4261-4277-a7b5-f96884bf7d36";
			case 40:
				return difficulty == 0 ? L"c11110ae-7fab-4f7f-8331-f1b4ac224fb0" : difficulty == 1 ? L"e5635f79-3eb1-49ee-937a-975d78759c31" : L"39b08af2-15c7-49dd-82d3-2946bda8be60";
			default:
				return L"";
			}

		case 5:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"68d73fc8-1a2e-4476-ba10-a60cbd56d455" : difficulty == 1 ? L"a2fc9e52-c5ba-4ef0-a7ca-ecee1eb6bf39" : L"824b3229-4111-41ba-ae5b-5571a4bdf04c";
			case 20:
				return difficulty == 0 ? L"3e9d6b86-771f-4ebe-9c18-b1f5902d957a" : difficulty == 1 ? L"c1814cc8-2056-4655-9ccc-7fb7d84cb3f3" : L"de8f7fea-f5e8-4626-94b2-a0e17dddfd28";
			case 30:
				return difficulty == 0 ? L"6ac709fd-c12a-484c-9eae-ce6d174bfcd9" : difficulty == 1 ? L"35f43a01-e71c-40b1-b470-733f6cfa243c" : L"a72ff27e-23fc-48f2-88e1-9be76c04c7f2";
			case 40:
				return difficulty == 0 ? L"cbddfe25-0e61-4e60-8821-260f6a1dbbae" : difficulty == 1 ? L"a07aeb73-467a-4973-a913-290c1a01219d" : L"b8178d7b-3179-4c0c-ba44-ab942ea38010";
			default:
				return L"";
			}

		case 6:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"374fb3f6-3e4b-40ad-9785-74f05cfec234" : difficulty == 1 ? L"ded3febc-e28b-44a6-b9d2-1a80362227ce" : L"8791a586-8090-46db-b86b-cfd1931f1dce";
			case 20:
				return difficulty == 0 ? L"704833af-7dea-4217-ad04-a7eb96bb86b6" : difficulty == 1 ? L"9f4ae8cc-cf76-4412-8a5d-a915c54972f3" : L"b87ac3b0-a9e5-4ddb-b293-c571e22aee37";
			case 30:
				return difficulty == 0 ? L"308ff880-9958-4dcc-b08e-434f38c80a0a" : difficulty == 1 ? L"b05cc2ba-d90f-44e4-8dcd-7d5072ba0d7a" : L"69fd424c-8744-40fe-be0e-5603fa6c89ba";
			case 40:
				return difficulty == 0 ? L"78febc02-4196-4a37-b574-99c108da9acf" : difficulty == 1 ? L"11628ab5-f7c7-41c9-b1ba-f03e1746b6b9" : L"6cd5d3de-067d-4316-bb7c-808c897a821b";
			default:
				return L"";
			}

		case 7:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"f7482c35-4582-483b-8c43-fa2b5b950747" : difficulty == 1 ? L"9a327f8a-500a-4bfa-b3cd-b4793db99989" : L"e3d02b02-2b6c-4d34-90e6-de49f83b80d1";
			case 20:
				return difficulty == 0 ? L"ed9e7647-fa4b-405c-9f6d-36ab1cdbe78a" : difficulty == 1 ? L"a467f319-0914-40c1-8a5b-ca2cb963c0c0" : L"8f7ae13b-387e-4264-828a-c0792204d49e";
			case 30:
				return difficulty == 0 ? L"5911bcca-cf90-4bdb-aefb-ba4b9404317e" : difficulty == 1 ? L"5cc50260-e473-4e32-9872-df5e5a92b411" : L"d0e2753e-7c75-49e7-8ca1-7a03a9b7110a";
			case 40:
				return difficulty == 0 ? L"74f0da34-52f2-4cde-8ae3-9ea3c25f6c63" : difficulty == 1 ? L"604f5bd9-9062-48e0-8792-80e4bda656ef" : L"2e68a18b-f2ba-488a-918e-13f02c576285";
			default:
				return L"";
			}

		case 8:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"77749564-6952-49a4-a9aa-d8d1994ba996" : difficulty == 1 ? L"e888a2d8-101b-4c5b-b0e3-a51294e5a33f" : L"e0370c85-9235-4037-bb1c-bd11cba763f2";
			case 20:
				return difficulty == 0 ? L"a80c977b-e127-4d63-8b8c-748cd5beabf8" : difficulty == 1 ? L"80303303-6af3-4f2b-b9ee-1a7613f56936" : L"38e3404f-8412-422b-b922-2f4fcbe39f71";
			case 30:
				return difficulty == 0 ? L"9e3c702a-8887-4455-94e4-49b898bca7f8" : difficulty == 1 ? L"dcda9fe0-8bf4-4c0a-a659-aa210675c32f" : L"216a5cc4-149d-4495-99e6-8c35bdbff336";
			case 40:
				return difficulty == 0 ? L"5fa593d6-9731-4840-b511-f6870802f0db" : difficulty == 1 ? L"12bb3f89-a0ee-4773-bd83-ab46fa41c95d" : L"6e912793-97b5-4b40-876d-cd7ce64ff8f3";
			default:
				return L"";
			}

		case 9:
			switch (wavesCompleted)
			{
			case 10:
				return difficulty == 0 ? L"792b57d3-7210-4c91-929f-5304c3120223" : difficulty == 1 ? L"31a9dbb5-dc02-4b21-b1e7-51dd4d699314" : L"8ae37aec-1172-480d-b199-d09be95f47a4";
			case 20:
				return difficulty == 0 ? L"adf7c480-cdd7-4cf4-9a82-dfc149ed38f1" : difficulty == 1 ? L"6d717baf-6925-422a-ac9d-1831b5b6fb87" : L"d3711041-2412-47b1-bf44-535c0aa6c7c4";
			case 30:
				return difficulty == 0 ? L"9d0857b8-61dc-4e73-b4b1-1cc8d1cfe412" : difficulty == 1 ? L"c6e4f00f-5886-4687-a3be-f2e61de7ed0a" : L"7e65fef3-ad45-4783-94f6-83b282e456b9";
			case 40:
				return difficulty == 0 ? L"0e33f54c-d698-4b33-a5e1-1b61a3164908" : difficulty == 1 ? L"9c3a4cb7-db81-4591-acc8-f89fc1d1e55c" : L"9d9663b0-892a-4fc2-b096-621e29fa0a1c";
			default:
				return L"";
			}
		default:
			return L"";
		}
	}

	static std::wstring GetIDForLevelUnlockAchievement(int difficulty, int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:
			return difficulty == 0 ? L"eb2075ef-7626-4d02-bcbd-688c1f5690c8" : difficulty == 1 ? L"673a63fb-0694-4b96-a7cc-aa7e8cd95e4c" : L"d2754a7d-a9fb-4d61-82d6-dd6cfd671db1";
		case 1:
			return difficulty == 0 ? L"9b831d72-a29e-48d6-947a-30b4ee7e8d5b" : difficulty == 1 ? L"b8fef65f-625b-488b-8266-024ece003aac" : L"84985c48-9cd2-40e5-9027-921bf73eee7a";
		case 2:
			return difficulty == 0 ? L"d834cdcd-2993-4fea-9e63-179d7219b88c" : difficulty == 1 ? L"be133bcc-a7a1-49c0-af94-a9a76d21280e" : L"5a2c86e0-21fa-4a72-9e46-1ee54bf781a7";
		case 3:
			return difficulty == 0 ? L"abfbb855-c0c9-4a72-aefd-2433e7ee28fe" : difficulty == 1 ? L"66f7a961-e473-4909-a8e7-f1ef7d466f85" : L"46081f6c-4ded-437c-8fa1-62ffef53bd80";
		case 4:
			return difficulty == 0 ? L"a4878a13-75b4-4ffb-a083-442d20a10eae" : difficulty == 1 ? L"6774d16c-7c32-4bed-ad5d-ded5e401a14d" : L"aad5791d-bc6d-4111-8da1-481dbd51d8ad";
		case 5:
			return difficulty == 0 ? L"07531045-5fa3-47d7-893f-985a934002ea" : difficulty == 1 ? L"a10f7f3a-de01-4302-aed5-08cb03a13e73" : L"aada1de0-d05d-4f59-8bde-217298dd5a88";
		case 6:
			return difficulty == 0 ? L"1960dc33-d4c2-406d-ab57-b1dc4f8f1b6a" : difficulty == 1 ? L"cd4c3c83-385c-48b5-8ba4-c44bfe3d5f7e" : L"5ee710e2-d035-4179-9b41-60e6acf74b08";
		case 7:
			return difficulty == 0 ? L"18001dd0-82ae-42c4-a45f-1c00cb5a7d4f" : difficulty == 1 ? L"74c2bef6-6fbd-42f7-a214-9df3a5210a5e" : L"c0d19b64-06dd-4958-99d5-305f44017fc8";
		case 8:
			return difficulty == 0 ? L"69890a32-0e69-4f06-8374-77c2a0b0948b" : difficulty == 1 ? L"a5a72601-131c-40df-9484-78dbf9530bdf" : L"0d5a37c9-2775-4ab8-9937-48f8e4e8e56a";
		case 9:
			return difficulty == 0 ? L"2bfb86ce-bdd3-40dc-9331-a9abf49b1505" : difficulty == 1 ? L"3e4f13a3-58f7-4aac-ad0d-914e307d70c2" : L"03b765fd-4853-4de0-9131-be0e0b064de9";
		default:
			return L"";
		}
	}

	static std::wstring getUnLockedMessageForLevelIndex(int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:
			return L"Freeze or Burn unlocked!";
		case 1:
			return L"Hull Damage unlocked!";
		case 2:
			return L"Clear a Path unlocked!";
		case 3:
			return L"Hangar Breach unlocked!";
		case 4:
			return L"Divided unlocked!";
		case 5:
			return L"Blitzkrieg unlocked!";
		case 6:
			return L"Full-scale War unlocked!";
		case 7:
			return L"Sabotoge unlocked!";
		case 8:
			return L"Finale unlocked!";
		default:
			return L"";
		}
	}

	static int getWaveRequirementForLevelIndex(int levelIndex)
	{
		switch (levelIndex)
		{
		case 0:
			return 20;
		case 1:
			return 30;
		case 2:
			return 30;
		case 3:
			return 30;
		case 4:
			return 20;
		case 5:
			return 30;
		case 6:
			return 20;
		case 7:
			return 50;
		case 8:
			return 40;
		case 9:
		default:
			return 60;
		}
	}
};

#endif /* defined(__insectoiddefense__AchievementMapper__) */