# SkillboxPatterns
������������ ������ UE 4.26.2
��� ���������� ��������� � ���� LogTemp
��� ��������� ���� ��� ������� � h ������. cpp ������������� UE.

## ����������� ������� (Abstract Factory)
��� ��������� � ����� \SkillboxPatterns\Source\SkillboxPatterns\AbstractFactory

������:
� ����������� �� ��������� (Steam, iOS ��� Android), �� ������� ������ �����, ���������:
- ���������� ��������� � ���
- ��������� ��������� ������ � ���� ������� ���������
- �������� ������������ ������ �� ��������� ������

������� ������� ������ BaseChat, BaseTop � BaseAchievement � ������������ ��������.
�� ������� ������� ����������� �������� ������ ��� ������ �� ��������. � ��� �������������� ������. ��� ����� ��� ���� ������� ��������� � ���.

������ ������� ����� ������� BaseFactory, ������� ����������� ������ ��� �������� ���� ���� ����������� ��� ������ ��������� �������.
��� ������ �� �������� ������� ���� ������� �� ������ ������ BaseFactory, ������� ������� ���������� ��� ���������� ���������.

��� �������� ����������������� ������, ������������� ����� StartPlay() ������ ASkillboxPatternsGameMode (��������� AGameModeBase).
����� ���������� ���������� PlatformType, ������� ��������� ������ ��������� ����� � ���������. 

��� ������ ���� � ���� ��������� ��������� � ��������� ��������� � ����������� ������ �������.

������ ��������, �� ���������� ������� ���������� ������ ��� ������ � ������� �����������.


## ��������� (Builder)
��� ��������� � ����� \SkillboxPatterns\Source\SkillboxPatterns\Builder

������:
��������� ��������� ����� / ������, ������� ����� ����� ��� �� ����� ��������� ���������:
- ������ � ����� ����
- ������ � ������ ����
- �����
- ���
- ������� �����
- ���������� �����
- ������������� ����������
- ������ ������ �� ����������

������ ����� Enemy, ������� ���������� ����� ��������� ��� ��������� �����.
������ ����� EnemyBuilder, ������� ������ ���������� ������. �� ���� ����������� ������ MobBuilder � BossBuilder. 
������ ����� EnemyDirector, � ������� ������������� �������� ���� ����� ������. 

��� �������� ����������������� ������, � ������ StartPlay() ������ ASkillboxPatternsGameMode �������� ����� ������� InitEnemies().
��� ������ ���� � ���� ��������� ��������� � ����������� �������� ������.


## �������� (Prototype)
��� ��������� � ����� \SkillboxPatterns\Source\SkillboxPatterns\Prototype

������:
������������ ��� �� ������� ������������� ��������:
- ����� ����� ��������
- ������� ����� ��������
- ���������� �������� �����

������ ������� ���� PrototypeItem, ������� ����� ����������� ����� ������������. 
�� ���� ����������� ����� LightItem � HealthPoitonItem, � �������� �������������� ������ ������������ � ��������� ������������� ��� ���� ������� ���������.
������ ����� LootManager, ������� ������ ������� ����. � ��� ������ ����� GetNewLootItem, ������� ���������� ����� �������� ��������� ����.

��� �������� � ������ StartPlay() ������ ASkillboxPatternsGameMode �������� ����� ������� InitLoot().
��� ������ ���� � ���� ��������� ��������� � ����������� ����������� ����.


## �������� (Singleton)
��� ��������� � ����� \SkillboxPatterns\Source\SkillboxPatterns\Singleton

������ ����� ��� ����������. � ������ ��������� ����� Get(), ������� ���������� ������ ��� �� ����. ��� �������� ��������� ��������� � �������� ������.
��� �������� � ������ StartPlay() ������ ASkillboxPatternsGameMode �������� ����� ������� InitConnect().