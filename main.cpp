#include "settings.h"

#define _WIN32_WINNT 0x0500
using namespace sf;


//RandomObjects arrow1;
sf::Clock vremya;
sf::Clock AngeloLife;
bool AngeloZiv = false;
Player player1;
Map Map1;
Map FightBackground;
Languages laungag;
Map ArrowSand;
Map Bonfire;
Stand playerstand;
Stand VragStand;
Shops ShopTutorial;
Powers timestoppower;
Powers Vragtimestoppower;

Powers WrOxyImage;
Vragi YopAngelo;
Vragi PlohoiParen;
Vragi DIO;
HUD MandomClockHUD;
NPC Haider;
NPC NPCDIO;
NPC NPCPlohoiParen;
InventoryPreview InvPR1;

Fights fightmenu1;
FightBackButton backbuttonfights;


HUD AngeloHealth;
VragiHealth fighthealth;
DayAndNight dayAndNight;
Aura plAura;
Aura VragAura;
CmoonRotate playerCmoonRotate;
CursorArrow cursor1;
ReloadingPowers ReloadBar1;
PlayerHealth hpbar;
Map House;
Map Shop;
GameOver gameover1;
Inventory PlayerInventory;
admincheats cheats;
SaveManager save1("saves\\save1.txt", player1, PlayerInventory);
PlayerAura playerAura(player1, playerstand);
bool teststeelballscharge = false;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    std::list<Laser*> laserSprites;
    std::list<Bubles*> BublesSprites;
    std::list<BarrageHands*> BarrageHandsSprites;
    std::list<DimensionClones*> DimensionClonesSprites;
    std::list<Notifications*> NotificationsTexts;
    std::list<SteelBall*> SteelBallsPlayerSprites;
    std::list<AerosmithBullet*> AerosmithBulletsSprites;
    std::list<TheWorldKnive*> TheWorldKnivesSprites;
    std::list<SheerHeartAttack*> SheerHeartAttackSprites;
    std::list<KqCoins*> KqCoinsSprites;
    std::list<GeTree*> GeTreeSprites;
    std::list<GeSoul*> GeSoulSprites;
    std::list<WsDisc*> WsDiscSprites;
    std::list<VragTheWorldKnive*> VragTheWorldKniveSprites;
        std::list<WsAcidCloud*> WsAcidCloudSprites;
    setlocale(LC_ALL, "Russian");
  
    ShopTutorial.SetShopItems(3, 2, 1);
  
    float MandomX = 0;
    float MandomY = 0;
    float MandomViewX = 0;
    float MandomViewY = 0;
    int MandomHealth = 0;
    float EmeraldSplashTmAttack = 450.f;
    float AerosmithHTmAttack = 100.f;
    float textgoap = 0.f;
    //меню

    sf::Image icon;
    icon.loadFromFile("icon.png");
    const sf::Uint8* pixels = icon.getPixelsPtr();

    LanguageFlags RU_FLAG;
    LanguageFlags USA_FLAG;
    LanguageFlagsInit(USA_FLAG, { 1000.f  ,1080.f / 2.f  }, "sprites\\USA.png");
    LanguageFlagsInit(RU_FLAG, { 100.f,1080.f / 2.f  }, "sprites\\RUSSIA.png");
    sf::Vector2i pixelPos;
    sf::Vector2f pos;
    Font font;
    font.loadFromFile("NjalBold.ttf");
    Text slLaung;
    slLaung.setCharacterSize(128);
    slLaung.setFont(font);
    slLaung.setPosition({ 0.f, 128.f });
    slLaung.setString(L"ВЫБЕРИ ЯЗЫК || CHOOSE LANGUAGE");
    RenderWindow SelectLaungage(sf::VideoMode::getDesktopMode(), "Select Laungage",
        Style::Titlebar | Style::Close | Style::Fullscreen);

    while (SelectLaungage.isOpen()) {
        pixelPos = sf::Mouse::getPosition(SelectLaungage);
        pos = SelectLaungage.mapPixelToCoords(pixelPos);
        if (RU_FLAG.sprite.getGlobalBounds().contains(pos.x, pos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                laungag.RussiaText = true;
                SelectLaungage.close();
            }
        }
        if (RU_FLAG.sprite.getGlobalBounds().contains(pos.x, pos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                laungag.RussiaText = true;
                SelectLaungage.close();
            }
        }if (USA_FLAG.sprite.getGlobalBounds().contains(pos.x, pos.y)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                laungag.EnglishText = true;
                SelectLaungage.close();
            }
        }
        Event eventda;
        while (SelectLaungage.pollEvent(eventda)) {

            if (eventda.type == sf::Event::Closed) {
                SelectLaungage.close();
                return 0;
            }
        }
       
        SelectLaungage.clear();
        SelectLaungage.draw(RU_FLAG.sprite);
        SelectLaungage.draw(USA_FLAG.sprite);
        SelectLaungage.draw(slLaung);
        SelectLaungage.display();
    }


    
    srand(time(NULL));
    Music music1;
    music1.openFromFile("music1.ogg");
    music1.play();
    music1.setVolume(30);
    music1.setLoop(true);
 



    Music WRtheme;
    WRtheme.openFromFile("sounds\\themes\\WR_Theme.ogg");
    WRtheme.setLoop(true);

    Music SAWtheme;
    SAWtheme.openFromFile("sounds\\themes\\SAW_Theme.ogg");
    SAWtheme.setLoop(true);
    
    Music ASTheme;
    ASTheme.openFromFile("sounds\\themes\\AerosmithTheme.ogg");
    ASTheme.setLoop(true);

    Music CmTheme;
    CmTheme.openFromFile("sounds\\themes\\CmTheme.ogg");
    CmTheme.setLoop(true);

    Music D4cTheme;
    D4cTheme.openFromFile("sounds\\themes\\D4cTheme.ogg");
    D4cTheme.setLoop(true);

    Music GeTheme;
    GeTheme.openFromFile("sounds\\themes\\GeTheme.ogg");
    GeTheme.setLoop(true);

    Music HgTheme;
    HgTheme.openFromFile("sounds\\themes\\HgTheme.ogg");
    HgTheme.setLoop(true);

    Music KqTheme;
    KqTheme.openFromFile("sounds\\themes\\KqTheme.ogg");
    KqTheme.setLoop(true);

    Music TwTheme;
    TwTheme.openFromFile("sounds\\themes\\TwTheme.ogg");
    TwTheme.setLoop(true);

    Music WsTheme;
    WsTheme.openFromFile("sounds\\themes\\WsTheme.ogg");
    WsTheme.setLoop(true);

    sf::SoundBuffer D4CDimensionhopbuffer;
    D4CDimensionhopbuffer.loadFromFile("sounds\\stands\\D4CDimensionHop.ogg");
    sf::Sound D4CDimensionhopsound(D4CDimensionhopbuffer);

    sf::SoundBuffer AerosmithHButtonbuffer;
    AerosmithHButtonbuffer.loadFromFile("sounds\\stands\\AerosmithHButtonSound.ogg");
    sf::Sound AerosmithHButtonSound(AerosmithHButtonbuffer);
    
    sf::SoundBuffer EmeraldSplashBuffer;
    EmeraldSplashBuffer.loadFromFile("sounds\\stands\\EmeraldSplash.ogg");
    sf::Sound EmeraldSplashsound(EmeraldSplashBuffer);

    sf::SoundBuffer standsummonbuffer;
    standsummonbuffer.loadFromFile("sounds\\stands\\stand_summon_sound.ogg");
    sf::Sound standsummonsound(standsummonbuffer);

    sf::SoundBuffer timestopbuffer;
    timestopbuffer.loadFromFile("sounds\\stands\\The_WORLD_time-stop.ogg");
    sf::Sound timestopsound(timestopbuffer);

    sf::SoundBuffer timeresumebuffer;
    timeresumebuffer.loadFromFile("sounds\\stands\\Time_Resume.ogg");
    sf::Sound timeresumesound(timeresumebuffer);

    sf::SoundBuffer MandomTimebuffer;
    MandomTimebuffer.loadFromFile("sounds\\stands\\Mandom_sound1.ogg");
    sf::Sound MandomTimesound(MandomTimebuffer);

    sf::SoundBuffer MandomClockEndbuffer;
    MandomClockEndbuffer.loadFromFile("sounds\\stands\\MandomClockEnd.ogg");
    sf::Sound MandomClockEndsound(MandomClockEndbuffer);
    MandomClockEndsound.setVolume(50.f);

    sf::SoundBuffer TwBarragebuffer;
    TwBarragebuffer.loadFromFile("sounds\\stands\\The_World_Barrage.ogg");
    sf::Sound TwBarragesound(TwBarragebuffer);

    sf::SoundBuffer SAWBarragebuffer;
    SAWBarragebuffer.loadFromFile("sounds\\stands\\SAWBarrage.ogg");
    sf::Sound SAWBarragesound(SAWBarragebuffer);

    sf::SoundBuffer WRBarragebuffer;
    WRBarragebuffer.loadFromFile("sounds\\stands\\WRbarrage.ogg");
    sf::Sound WRBarragesound(WRBarragebuffer);

    sf::SoundBuffer KQBarragebuffer;
    KQBarragebuffer.loadFromFile("sounds\\stands\\KQBarrageSound.ogg");
    sf::Sound KQBarragesound(KQBarragebuffer);

    sf::SoundBuffer GeTreeSummonbuffer;
    GeTreeSummonbuffer.loadFromFile("sounds\\stands\\GeTreeSummon.ogg");
    sf::Sound GeTreeSummonSound(GeTreeSummonbuffer);



    RenderWindow window(sf::VideoMode::getDesktopMode(), "Traveler's Bizzare Adventure",
        Style::Titlebar | Style::Close | Style::Fullscreen );
   

   

    window.setKeyRepeatEnabled(false);
 
   // window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    window.setIcon(icon.getSize().x, icon.getSize().y, pixels);




    sf::View view(sf::FloatRect(0.f, 0.f, WINDOW_X, WINDOW_Y));
    view.setCenter(player1.sprite.getPosition()); // устанавливаем центр камеры на игрока
    window.setView(view);
    NPCInit(Haider, "sprites\\npc\\HaiderLoh.png", { 1578 ,360.f });
    NPCInit(NPCPlohoiParen, "sprites\\npc\\PlohoiParen.png", { 2967.f, 412.f });
    NPCInit(NPCDIO, "sprites\\npc\\PlohoiParen.png", { 325.f,1640.f });
    HudInit(MandomClockHUD, "sprites\\hud\\MandomClock1.png");
   // HudInit(InventoryArrow, "sprites\\hud\\ARROW.png");
    HudInit(AngeloHealth, "sprites\\hud\\angeloHealth10.png");

    VragiInit(YopAngelo, "sprites\\npc\\YoAngelo.png", 0, 100.f,{ 2377.f,1064.f }, true,"Yo Angelo",0);
    VragiInit(PlohoiParen, "sprites\\npc\\PlohoiParenLeft.png", 1, 100.f, { 0,0 }, false, "Bad Guy", 1000);
    VragiInit(DIO, "sprites\\npc\\PlohoiParenLeft.png", 2, 300.f, { 0.f,0.f }, false, "DIO", 3000);

    PowrsObjectsINIT(timestoppower, "sprites\\powers\\TimeStop.png");
    PowrsObjectsINIT(Vragtimestoppower, "sprites\\powers\\TimeStop.png");
    PowrsObjectsINIT(WrOxyImage, "sprites\\powers\\WRoxygen.png");

    StandInit(playerstand, "sprites\\stands\\THE_WORLD_RIGHT.png");
    StandInit(VragStand, "sprites\\stands\\THE_WORLD_RIGHT.png");
    // RandomObjectsINIT(arrow1, ARROW_FILE_NAME); 
    PlayerInit(player1, PLAYER1RIGHT_FILE_NAME);
   
    MapObjectsINIT(FightBackground, "sprites\\map\\FightBackground.png", { -480.f,423.f });

    MapObjectsINIT(Bonfire, "sprites\\map\\BonfireOff.png", { 369.f,1667.f });
    MapObjectsINIT(Map1, "sprites\\map\\MAP.png", { 0,0 });
    MapObjectsINIT(ArrowSand, "sprites\\map\\SANDARROWS.png", { 1567,1654 });
    MapObjectsINIT(House, "sprites\\map\\House.png", { 851,580 });
    MapObjectsINIT(Shop, "sprites\\map\\Shop.png", {504.f,807.f});

  
    

    AuraInit(plAura, "sprites\\stands\\auras\\TwAuraFrame1.png");
    AuraInit(VragAura, "sprites\\stands\\auras\\TwAuraFrame1.png");
    sf::View view2(sf::FloatRect(0.f, 0.f, 960, 540));
   

    //  Text HealthAngeloTest(std::to_string(YopAngelo.health), font, 160);
    Text VersionText(VERSION_NAME, font, 50);
   // Text ArrowKolInv(std::to_string(ArrowInv), font, 40);
   // ArrowKolInv.setFillColor(sf::Color::Black);
   
    float time;

    Menu menu1(laungag, player1, PlayerInventory);
    while (window.isOpen()) {
       

        time = vremya.getElapsedTime().asMicroseconds();
        vremya.restart();
        time = time / 800.f;
         pixelPos = sf::Mouse::getPosition(window);
         pos = window.mapPixelToCoords(pixelPos);
         cursor1.update(pos);
        Event event;

        while (MenuOn == true) {
            time = vremya.getElapsedTime().asMicroseconds();
            vremya.restart();
            time = time / 800.f;
            view.setCenter(960, 540);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            view.setRotation(0.f);
            menu1.update(pos,window);
            
            menu1.draw(VersionText, cursor1, window);
            menu1.setViewMenu(true);
            cursor1.update(pos);
            if (menu1.getClose() == true) {
                return 0;
            }

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return 0;
                }
            }
        }
        if (menu1.getClose() == true) {
            return 0;
        }
        while (GameOverOn == true) {
            view.setRotation(0.f);
            view.setCenter(960, 540);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            gameover1.update(pos);
            gameover1.draw(cursor1, window);
            gameover1.setViewMenu(true);
            cursor1.update(pos);


            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return 0;
                }
            }
        }

        while (ShopTutorial.getOpen() == true) {
            view.setRotation(0.f);
            time = vremya.getElapsedTime().asMicroseconds();
            vremya.restart();
            time = time / 800.f;
            sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            PlayerInventory.update({ view.getCenter().x + 24, view.getCenter().y + 136 }, { view.getCenter().x - 234, view.getCenter().y + 100 }, player1, pos, laungag);
            ShopTutorial.update(laungag, pos,player1);
            window.clear();
            ShopTutorial.draw(window);
         
            cursor1.update(pos);
            cursor1.draw(window);
            window.display();

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return 0;
                }
                else { ShopTutorial.updatedva(PlayerInventory, player1,pos); }
            }
        }


        backbuttonfights.restartClock();
        while (fightmenu1.getFight() == true) {
            if (player1.stand == 1 && TwTheme.getStatus() == sf::SoundSource::Status::Stopped) {
                TwTheme.play();
           }
            else if (player1.stand == 3 && WRtheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                WRtheme.play();
            }
            else if (player1.stand == 4 && HgTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                HgTheme.play();
            }
            else if (player1.stand == 5 && SAWtheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                SAWtheme.play();
            }
            else if (player1.stand == 6 && D4cTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                D4cTheme.play();
            }
            else if (player1.stand == 7 && ASTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                ASTheme.play();
            }
            else if (player1.stand == 8 && KqTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                KqTheme.play();
            }
            else if (player1.stand == 9 && GeTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                GeTheme.play();
            }
            else if (player1.stand == 10 && WsTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                WsTheme.play();
            }
            else if (player1.stand == 11 && CmTheme.getStatus() == sf::SoundSource::Status::Stopped)
            {
                CmTheme.play();
            }
            if (MandomX >= 1920.f || MandomX <= 0.f) {
                MandomX = 900.f;
            }
            if (MandomY > 840.f || MandomY < 840.f) {
                MandomY = 840.f;
            }
            time = vremya.getElapsedTime().asMicroseconds();
            vremya.restart();
            time = time / 800.f;
           
            view2.setCenter(player1.sprite.getPosition().x + 22, player1.sprite.getPosition().y - 50.f);
            window.setView(view2);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            if (fightmenu1.getVrag()->health <= 0) {
                player1.money += fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.intimestopdio = false;
                Notifications* Notificationstext = nullptr;
              
                    TwTheme.stop();                            
                    WRtheme.stop();
                    HgTheme.stop();
                    SAWtheme.stop();
                    D4cTheme.stop();
                    ASTheme.stop();
                    KqTheme.stop();
                    GeTheme.stop();
                    WsTheme.stop();
                    CmTheme.stop();
                
           
                    if (laungag.EnglishText == true) {
                        Notificationstext = new Notifications(L"+" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" money");
                    }
                    else if (laungag.RussiaText == true) {
                        Notificationstext = new Notifications(L"+" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" денег");
                    }

                    NotificationsTexts.push_back(Notificationstext);
                    if (fightmenu1.getVrag()->Name == "DIO" && rand() % 3 == 1) {
                        Notifications* Notificationstext = nullptr;
                        PlayerInventory.addItem(9);

                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Dio Bone");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Dio Bone");
                        }

                        NotificationsTexts.push_back(Notificationstext);
               }
            }
          
            if (player1.health <= 0.f) {
                player1.money -= fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                player1.health = 1.f;
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.intimestopdio = false;
                Notifications* Notificationstext = nullptr;

                TwTheme.stop();
                WRtheme.stop();
                HgTheme.stop();
                SAWtheme.stop();
                D4cTheme.stop();
                ASTheme.stop();
                KqTheme.stop();
                GeTheme.stop();
                WsTheme.stop();
                CmTheme.stop();
                if (laungag.EnglishText == true) {
                    Notificationstext = new Notifications(L"-" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" money");
                }
                else if (laungag.RussiaText == true) {
                    Notificationstext = new Notifications(L"-" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" денег");
                }

                NotificationsTexts.push_back(Notificationstext);
            }
            VragiAuraUpdate(VragAura, *fightmenu1.getVrag(), VragStand, time);
            AuraUpdate(plAura, player1, playerstand, time);
            fighthealth.update({ view2.getCenter().x + 350.f - fighthealth.getSprite().getGlobalBounds().width , view2.getCenter().y - 250.f }, *fightmenu1.getVrag());
            PlayerUpdateInFight(player1, PLAYER1LEFT_FILE_NAME, "sprites\\player\\player1rightmove1.png", "sprites\\player\\player1leftmove1.png", PLAYER1RIGHT_FILE_NAME, playerstand, time);
            StandUpdate(playerstand, player1, time);
            if (isTimeStopped == false) {
                Powersbjupdate(timestoppower, { player1.sprite.getPosition().x - 370, player1.sprite.getPosition().y - 425 }, 1);
            }
            if (VragIsTimeStopped == false) {
                Powersbjupdate(Vragtimestoppower, { fightmenu1.getVrag()->sprite.getPosition().x - 370,  fightmenu1.getVrag()->sprite.getPosition().y - 425 }, 1);
            }
            VragiStandUpdate(VragStand, *fightmenu1.getVrag(), time);
            VragiUpdate(*fightmenu1.getVrag(), VragStand, player1, time);
            Mapbjupdate(FightBackground);
            backbuttonfights.update({ view2.getCenter().x + 350.f, view2.getCenter().y + 250.f - backbuttonfights.getSprite().getGlobalBounds().height }, pos);
            VragiBarrageDamage(player1, time, *fightmenu1.getVrag(), VragStand);
            BarrageDamage(*fightmenu1.getVrag(), time, player1, playerstand);
            if (D4CDimension == true && Gbuttontime.getElapsedTime().asSeconds() >= 20) {
                D4CDimension = false;
            }
            if (D4CDimension == true && player1.stand != 6) {
                D4CDimension = false;
            }
            cursor1.update(pos);
            window.clear();
            MapObjectsDraw(window, FightBackground);

            AuraDraw(window, plAura);
            if (D4CDimension == false) {
                AuraDraw(window, VragAura);
            }
            for (auto laser : laserSprites) {
                laser->update();
            }
            for (auto bubles : BublesSprites) {
                bubles->update();
            }
            for (auto aerosmithBullet : AerosmithBulletsSprites) {
                aerosmithBullet->update(time);
            }
            for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
                SheerHeartAttacks->update(time);
            }
            for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
                SheerHeartAttackDamage(*SheerHeartAttacks, SheerHeartAttackSprites);
            }
            for (auto kqcoins : KqCoinsSprites) {
                kqcoins->update();
            }
            for (auto GeTree : GeTreeSprites) {
                GeTree->update(*GeTree, time, *fightmenu1.getVrag());
            }
            for (auto kqcoins : KqCoinsSprites) {
                KqCoinsDamage(*kqcoins, KqCoinsSprites, *fightmenu1.getVrag());
            }
            if (CmoonRotateSpawn == true) {
                CmoonRotateSpawn = false;
                playerCmoonRotate.Activate();
            }
          
            PlayerDraw(window, player1);
         
            fighthealth.Draw(window);
            StandDraw(window, playerstand);
            if (D4CDimension == false) {
                StandDraw(window, VragStand);
            }
            if (isTimeStopped == true && timestop.getElapsedTime().asSeconds() < 10.f) {
                if (timestop.getElapsedTime().asSeconds() < 1.f) {
                    timestopsound.play();
                }
                timestoppower.visible = true;
            }
            if (VragIsTimeStopped == true && VragPowerH.getElapsedTime().asSeconds() < 10.f) {
                if (VragPowerH.getElapsedTime().asMilliseconds() < 100.f) {
                    timestopsound.play();
                }
                Vragtimestoppower.visible = true;
            }
            if (isTimeStopped == true && timestop.getElapsedTime().asSeconds() > 10.f) {
                isTimeStopped = false;
                timeresumesound.play();
                timestoppower.visible = false;
                

            }
            if (VragIsTimeStopped == true && VragPowerH.getElapsedTime().asSeconds() > 10.f) {
                VragIsTimeStopped = false;
                timeresumesound.play();
                Vragtimestoppower.visible = false;

            }
            if (isMandomTime == false && MandomTime.getElapsedTime().asSeconds() > 6.f) {
                if (player1.stand == 2) {
                    MandomClockEndsound.play();
                }
                MandomTime.restart();
                MandomX = player1.sprite.getPosition().x;
                MandomY = player1.sprite.getPosition().y;
                MandomViewX = view2.getCenter().x;
                MandomViewY = view2.getCenter().y;
                MandomHealth = player1.health;

            }
            if (isWrOxy == true && WROxy.getElapsedTime().asSeconds() <= 1) {
                WrOxyImage.sprite.setPosition(playerstand.sprite.getPosition());
                WrOxyImage.visible = true;
            }

            if (fightmenu1.getVrag()->sprite.getGlobalBounds().intersects(timestoppower.sprite.getGlobalBounds()) && isTimeStopped == true) {
               
                fightmenu1.getVrag()->stoppedbytime = true;
            }
            if (fightmenu1.getVrag()->stoppedbytime == true && isTimeStopped == false) {
                fightmenu1.getVrag()->stoppedbytime = false;
            }
            if (player1.sprite.getGlobalBounds().intersects(Vragtimestoppower.sprite.getGlobalBounds()) && VragIsTimeStopped == true) {

                player1.intimestopdio = true;
            }
            if (player1.intimestopdio == true && VragIsTimeStopped == false) {
                player1.intimestopdio = false;
            }
            MandomClock(MandomTime, MandomClockHUD);

            for (auto dimensionClones : DimensionClonesSprites) {
                DimensionClonesDamage(*dimensionClones, DimensionClonesSprites);
            }
            for (auto laser : laserSprites) {
                LaserDamage(*laser, laserSprites, *fightmenu1.getVrag());
            }
            for (auto GeTree : GeTreeSprites) {
                GeTreesDamage(*GeTree, GeTreeSprites);
            }
            for (auto gesoul : GeSoulSprites) {
                gesoul->update(*gesoul, time);
            }
            for (auto gesoul : GeSoulSprites) {
                GeSoulDamage(*gesoul, GeSoulSprites);
            }
            for (auto WsDisc : WsDiscSprites) {
                WsDisc->update();
            }
            for (auto WsAcid : WsAcidCloudSprites) {
                WsAcid->update(playerstand, *fightmenu1.getVrag());
            }
            for (auto WsAcid : WsAcidCloudSprites) {
                WsAcidCloudDamage(*WsAcid, WsAcidCloudSprites);
            }
            for (auto WsDisc : WsDiscSprites) {
                WsDiscDamage(*WsDisc, WsDiscSprites);
            }
            for (auto barragehands : BarrageHandsSprites) {
                barragehands->update();
            }
            for (auto bubles : BublesSprites) {
                BublesDamage(*bubles, BublesSprites, *fightmenu1.getVrag());
            }
            for (auto barragehands : BarrageHandsSprites) {
                DeleteBarrageHands(*barragehands, BarrageHandsSprites);
            }
            for (auto steelballs : SteelBallsPlayerSprites) {
                SteelBallsDamage(*steelballs, SteelBallsPlayerSprites, *fightmenu1.getVrag());
            }
            for (auto steelballs : SteelBallsPlayerSprites) {
                steelballs->update(time);
            }
            for (auto VragTheWorld : VragTheWorldKniveSprites) {
                VragTheWorld->update(time,Vragtimestoppower);
            }
            for (auto VragTheWorld : VragTheWorldKniveSprites) {
                VragTheWorldKnivesDamage(*VragTheWorld, VragTheWorldKniveSprites,player1);
                    
            }
            WrOxyDamagePl(WrOxyImage, player1, time);
            WrOxyDamageVragov(WrOxyImage, *fightmenu1.getVrag(), time);
            if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asMilliseconds() > EmeraldSplashTmAttack) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2 - 44,	pos.y + bounds.height / 2 };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
                }

                Laser* laser = new Laser(posCenter, player1,time);
                laserSprites.push_back(laser);
                EmeraldSplashTmAttack += 450.f;

            }
            if (WsAcidSpawn == true) {
           
                WsAcidCloud* WsAcidClouds = new  WsAcidCloud(YopAngelo,playerstand);
                WsAcidCloudSprites.push_back(WsAcidClouds);
                WsAcidSpawn = false;
          
        }
            if (GeTreeSpawn == true) {
                sf::Vector2f pos;
                if (player1.left == true) {
                    pos = { player1.sprite.getPosition().x,  player1.sprite.getPosition().y - player1.sprite.getGlobalBounds().height };
                }
                else  if (player1.left == false) {
                    pos = { player1.sprite.getPosition().x + player1.sprite.getGlobalBounds().width + 2.f, player1.sprite.getPosition().y - player1.sprite.getGlobalBounds().height };
                }

                GeTree* getree = new GeTree(pos, player1.left);
                GeTreeSprites.push_back(getree);
                GeTreeSpawn = false;
                GeTreeSummonSound.play();
            }
            if (GeSoulPunch == true) {
                sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
                StandBounds.width += 30.f;
                sf::Vector2f pos = fightmenu1.getVrag()->sprite.getPosition();
                if (StandBounds.intersects(fightmenu1.getVrag()->sprite.getGlobalBounds())) {
                    GeSoul* GeSouls = new GeSoul(pos, *fightmenu1.getVrag());
                    GeSoulSprites.push_back(GeSouls);
                    GeSoulPunch = false;
                }
            }
            if (WsAcidSpawn == true) {

                WsAcidCloud* WsAcidClouds = new  WsAcidCloud(YopAngelo, playerstand);
                WsAcidCloudSprites.push_back(WsAcidClouds);
                WsAcidSpawn = false;

            }
            for (auto theworldknives : TheWorldKnivesSprites) {
                theworldknives->update(time, timestoppower);
            }
            for (auto theworldknives : TheWorldKnivesSprites) {
                TheWorldKnivesDamage(*theworldknives, TheWorldKnivesSprites, *fightmenu1.getVrag());
            }
            for (auto aerosmithBullet : AerosmithBulletsSprites) {

                AerosmithBulletsDamage(*aerosmithBullet, AerosmithBulletsSprites, *fightmenu1.getVrag());
            }
            if (KqCoinSpawn == true) {
         

                sf::Vector2f pos = player1.sprite.getPosition();



                if (player1.left == true) {
                    pos = sf::Vector2f{ pos.x - player1.sprite.getGlobalBounds().width,	pos.y + player1.sprite.getGlobalBounds().height };
                }
                if (player1.left == false) {
                    pos = sf::Vector2f{ pos.x + player1.sprite.getGlobalBounds().width,	pos.y + player1.sprite.getGlobalBounds().height };
                }

                KqCoins* kqcoins = new KqCoins(pos, player1, time);
                KqCoinsSprites.push_back(kqcoins);
                KqCoinSpawn = false;
            }
            if (TheWorldKniveSpawn == true) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0.f,	0.f };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f - 44,	pos.y + bounds.height / 2.f };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f,	pos.y + bounds.height / 2.f };
                }

                TheWorldKnive* theworldknive = new TheWorldKnive(posCenter, player1);
                TheWorldKnivesSprites.push_back(theworldknive);
                TheWorldKniveSpawn = false;
            }
            if (AerosmithHbutton == true && Hbuttontime.getElapsedTime().asSeconds() <= 10 && Hbuttontime.getElapsedTime().asMilliseconds() >= AerosmithHTmAttack) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x  ,	pos.y + bounds.height / 2 };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
                }

                AerosmithBullet* aerosmithbullet = new AerosmithBullet(posCenter, player1);
                AerosmithBulletsSprites.push_back(aerosmithbullet);
                AerosmithHTmAttack += 50.f;

            }
            if (AerosmithHbutton == true && Hbuttontime.getElapsedTime().asSeconds() >= 7 || AerosmithHbutton == false) {
                AerosmithHbutton = false;
                AerosmithHTmAttack = 100.f;
            }
            if (player1.attacking == true) {
                if (player1.FightTech == 1) {
                    sf::Vector2f pos = player1.sprite.getPosition();
                    sf::FloatRect bounds = player1.sprite.getGlobalBounds();
                    sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                    if (player1.left == true) {
                        posCenter = sf::Vector2f{ pos.x + bounds.width / 2 - 44,	pos.y + bounds.height / 2 };
                    }
                    if (player1.left == false) {
                        posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
                    }
                    SteelBall* steelballs = new SteelBall(posCenter, player1, teststeelballscharge);
                    SteelBallsPlayerSprites.push_back(steelballs);
                }
                player1.attacking = false;
            }
            if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asMilliseconds() < 200.f) {

                if (player1.stand == 1) {
                    TwBarragesound.play();
                }
                else if (player1.stand == 3) {
                    WRBarragesound.play();
                }
                else if (player1.stand == 4) {

                }
                else if (player1.stand == 5) {
                    SAWBarragesound.play();
                }
               
                else if (player1.stand == 8) {
                    KQBarragesound.play();
                }
            }
            hpbar.update(view2.getCenter(), player1, fightmenu1.getFight());
            if (SAWBublCreate == true) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f - 44.f,	pos.y + bounds.height / 2.f };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f,	pos.y + bounds.height / 2.f };
                }

                Bubles* bubles = new Bubles(posCenter, player1, time);
                BublesSprites.push_back(bubles);
                SAWBublCreate = false;
            }

            if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asMilliseconds() < 400.f) {
                EmeraldSplashsound.play();

            }
            if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asSeconds() > 10.f) {
                isEmeraldSplash = false;

                EmeraldSplashTmAttack = 450.f;
            }
            if (D4CDimensionClones == true) {
                sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
              
                sf::Vector2f pos = playerstand.sprite.getPosition();
                if (StandBounds.intersects(fightmenu1.getVrag()->sprite.getGlobalBounds())) {
                    DimensionClones* dimensionClones = new DimensionClones(pos, *fightmenu1.getVrag());
                    DimensionClonesSprites.push_back(dimensionClones);
                    D4CDimensionClones = false;
                }
            }
           

            if (Hbuttontime.getElapsedTime().asSeconds() >= 10 && D4CDimensionClones == true) {
                D4CDimensionClones = false;
            }
            if (playerstand.barrage == true) {

                sf::Vector2f pos = playerstand.sprite.getPosition();
                BarrageHands* barragehands = new BarrageHands(pos, player1);
                BarrageHandsSprites.push_back(barragehands);

            }
            if (WsDiscSpawn == true) {
                sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
                StandBounds.width += 50.f;
                sf::Vector2f pos = { playerstand.sprite.getPosition().x, playerstand.sprite.getPosition().y + playerstand.sprite.getGlobalBounds().height };
                if (StandBounds.intersects(fightmenu1.getVrag()->sprite.getGlobalBounds())) {
                    WsDisc* WsDiscs = new  WsDisc(*fightmenu1.getVrag());
                    WsDiscSprites.push_back(WsDiscs);
                    WsDiscSpawn = false;
                    
                }
            }
            if (SheertHeartAttackSpawn == true) {
                sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();

                sf::Vector2f pos = { playerstand.sprite.getPosition().x, playerstand.sprite.getPosition().y + playerstand.sprite.getGlobalBounds().height};
               
                    SheerHeartAttack* SheerHeartAttacks = new SheerHeartAttack(pos, *fightmenu1.getVrag());
                    SheerHeartAttackSprites.push_back(SheerHeartAttacks);
                    SheertHeartAttackSpawn = false;
               
            }
            if (VragTwKnifeSpawn == true) {
                sf::Vector2f pos = VragStand.sprite.getPosition();
                sf::FloatRect bounds = VragStand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0.f,	0.f };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f - 44,	pos.y + bounds.height / 2.f };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f,	pos.y + bounds.height / 2.f };
                }
              
                VragTheWorldKnive* VragTheWorldKnives = new  VragTheWorldKnive(posCenter, *fightmenu1.getVrag());
                VragTheWorldKniveSprites.push_back(VragTheWorldKnives);
                VragTwKnifeSpawn = false;

            }
            if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asSeconds() > 5.f && player1.stand != 5) {
                playerstand.barrage = false;
            }
            else if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asSeconds() > 3.f && player1.stand == 5) {
                playerstand.barrage = false;
            }
            if (WROxy.getElapsedTime().asSeconds() > 10.f) {
                isWrOxy = false;
                WrOxyImage.visible = false;
            }
            if (isMandomTime == true) {
                MandomTimesound.play();
                MandomTime.restart();
                view2.setCenter(MandomViewX, MandomViewY);
                player1.sprite.setPosition(MandomX, MandomY);
                playerstand.sprite.setPosition(MandomX, MandomY);
                player1.health = MandomHealth;
                isMandomTime = false;

            }

            if (D4CDimension == true && Gbuttontime.getElapsedTime().asMilliseconds() <= 100) {
                D4CDimensionhopsound.play();
            }
            if (player1.stand != 4 || playerstand.visible == false) {
                isEmeraldSplash = false;
                EmeraldSplashsound.stop();
            }



            VragiDraw(window, *fightmenu1.getVrag());

            for (auto dimensionClones : DimensionClonesSprites) {
                window.draw(dimensionClones->getSprite());
            }


            for (auto laser : laserSprites) {
                window.draw(laser->getSprite());
            }
            for (auto barragehands : BarrageHandsSprites) {
                window.draw(barragehands->getSprite());
            }
            for (auto GeTree : GeTreeSprites) {
                GeTree->draw(window);
            }
            for (auto bubles : BublesSprites) {
                window.draw(bubles->getSprite());
            }
            for (auto steelballs : SteelBallsPlayerSprites) {
                steelballs->draw(window);
            }
            for (auto aerosmithBullet : AerosmithBulletsSprites) {
                aerosmithBullet->draw(window);
            }
            for (auto theworldknives : TheWorldKnivesSprites) {
                theworldknives->draw(window);
            }
            for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
                SheerHeartAttacks->draw(window);
            }
            for (auto kqcoins : KqCoinsSprites) {
                kqcoins->draw(window);
            } 
            for (auto gesoul : GeSoulSprites) {
                gesoul->draw(window);
            }
            for (auto WsDisc : WsDiscSprites) {
                WsDisc->draw(window);
            }
            for (auto VragTheWorld : VragTheWorldKniveSprites) {
                VragTheWorld->draw(window);
            }
            PowersObjectsDraw(window, Vragtimestoppower);
            PowersObjectsDraw(window, timestoppower);
            PowersObjectsDraw(window, WrOxyImage);
            for (auto WsAcid : WsAcidCloudSprites) {
                WsAcid->draw(window);
            }
            if (player1.stand == 2) {
                HudDraw(window, MandomClockHUD);
            }
      
            hpbar.Draw(window);
            backbuttonfights.draw(window);
            playerCmoonRotate.update(*fightmenu1.getVrag(), view2);
            ReloadBar1.update({ view2.getCenter().x - 470.f , view2.getCenter().y + 80.f }, Hbuttontime, Gbuttontime,Barrageplayer, player1);
            ReloadBar1.draw(window, Hbuttontime, Gbuttontime, Barrageplayer);
            cursor1.draw(window);
            dayAndNight.update({ view2.getCenter().x - 960.f,view2.getCenter().y - 540.f });
            if (fightmenu1.getVrag()->Name == "DIO") {
                dayAndNight.setNight(true);
            }
            if (D4CDimension == false) {
                dayAndNight.draw(window);
            }
            if (backbuttonfights.getClose() == true && backbuttonfights.getValidSur() == true) {
                backbuttonfights.setClose(false);
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.intimestopdio = false;
                TwTheme.stop();
                WRtheme.stop();
                HgTheme.stop();
                SAWtheme.stop();
                D4cTheme.stop();
                ASTheme.stop();
                KqTheme.stop();
                GeTheme.stop();
                WsTheme.stop();
                CmTheme.stop();
            }
            else  if (backbuttonfights.getClose() == true) {
                TwTheme.stop();
                WRtheme.stop();
                HgTheme.stop();
                SAWtheme.stop();
                D4cTheme.stop();
                ASTheme.stop();
                KqTheme.stop();
                GeTheme.stop();
                WsTheme.stop();
                CmTheme.stop();
                backbuttonfights.setClose(false);
                player1.money -= fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
              
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.intimestopdio = false;
                Notifications* Notificationstext = nullptr;


                if (laungag.EnglishText == true) {
                    Notificationstext = new Notifications(L"-" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" money");
                }
                else if (laungag.RussiaText == true) {
                    Notificationstext = new Notifications(L"-" + std::to_wstring(fightmenu1.getVrag()->Reward) + L" денег");
                }

                NotificationsTexts.push_back(Notificationstext);
            }
            window.display();
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return 0;
                }
                else if (event.type == sf::Event::KeyReleased &&
                    event.key.code == sf::Keyboard::Q && playerstand.visible == false && player1.stand != 0)
                {
                    standsummonsound.play();
                    StandSummon(player1, playerstand);
                    playerstand.visible = true;
                }
                else if (event.type == sf::Event::KeyReleased &&
                    event.key.code == sf::Keyboard::Q && playerstand.visible == true && player1.stand != 0)
                {
                    playerstand.visible = false;
                }
            }
        }


        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }

            else if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Q && playerstand.visible == false && player1.stand != 0)
            {
                standsummonsound.play();
                StandSummon(player1, playerstand);
                playerstand.visible = true;
            }
            else if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Q && playerstand.visible == true && player1.stand != 0)
            {
                playerstand.visible = false;
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::E && player1.sprite.getGlobalBounds().intersects(ArrowSand.sprite.getGlobalBounds())) {

                if (rand() % 5 == 1) {
                    Notifications* Notificationstext = nullptr;
                    if (PlayerInventory.ItemCanBeAdded(1)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Arrow");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Стрела");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(1);
                    
                    
                }
                else if (rand() % 5 == 1) {

                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(2)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Rokaka");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Рокака");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(2);
                }
                else if (rand() % 10 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(4)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Tonio Food");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Еда Тонио");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(4);
                }
               else if (rand() % 50 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(3)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Dio Diary");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Дневник Дио");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(3);
                }

                /*else if (rand() % 20 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(5)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Heart Of The Saints Corpse");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Сердце Святого Трупа");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(5);
                }*/
               /* else if (rand() % 20 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(6)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ RibCage Of The Saints Corpse");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Ребро Святого Трупа");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(6);
                }*/
                else if (rand() % 20 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(7)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Legs Of The Saints Corpse");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Ноги Святого Трупа");
                        }

                        NotificationsTexts.push_back(Notificationstext);
                    }
                    PlayerInventory.addItem(7);
                }
                else if (rand() % 20 == 1) {
                Notifications* Notificationstext = nullptr;

                if (PlayerInventory.ItemCanBeAdded(8)) {
                    if (laungag.EnglishText == true) {
                        Notificationstext = new Notifications(L"+ Steel Ball");
                    }
                    else if (laungag.RussiaText == true) {
                        Notificationstext = new Notifications(L"+ Стальной шар");
                    }

                    NotificationsTexts.push_back(Notificationstext);
                }
                PlayerInventory.addItem(8);
                }
            }


            /*  else  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::U) {
                   saveGame(player1, quest1, quest2, player1.sprite.getPosition().x, player1.sprite.getPosition().y);
               }

               else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::I) {
                   loadGame(player1, quest1, quest2, player1.sprite.getPosition().y, player1.sprite.getPosition().x);

               }*/
           
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
                MenuOn = true;
            }

            else if (InvPR1.getHitbox().contains(pos.x, pos.y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    if (PlayerInventory.getOpen() == false) {
                        PlayerInventory.setOpen(true);
                    }
                    else   if (PlayerInventory.getOpen() == true) {
                        PlayerInventory.setOpen(false);
                    }
                }
            }

            /*   else if (event.type == sf::Event::MouseButtonPressed) {
                   if (Mouse::isButtonPressed(Mouse::Left)) {
                       if (InventoryArrow.sprite.getGlobalBounds().contains(pos.x, pos.y)) {

                           if (ArrowInv > 0) {

                               --ArrowInv;
                           }
                       }

                   }
               }
               */

        }







        /* if (playerstand.visible == true) {
             if (player1.stand == 3) {
                 if (WRtheme.getStatus() == 0 || WRtheme.getStatus() == 1) {
                     WRtheme.play();
                 }
             }
             else {
                 WRtheme.stop();
             }
             if (player1.stand == 5) {
                 if (SAWtheme.getStatus() == 0 || SAWtheme.getStatus() == 1) {
                     SAWtheme.play();
                 }
             }
             else {
                 SAWtheme.stop();
             }
         }
         else {
             WRtheme.stop();
             SAWtheme.stop();
         }*/


        if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asMilliseconds() < 100) {

            if (player1.stand == 1) {
                TwBarragesound.play();
            }
            if (player1.stand == 3) {
                WRBarragesound.play();
            }
            if (player1.stand == 4) {

            }
            if (player1.stand == 5) {
                SAWBarragesound.play();
            }   
            else if (player1.stand == 8) {
                KQBarragesound.play();
            }
        }


       
        if (D4CDimension == false) {

            if (player1.sprite.getGlobalBounds().intersects(ArrowSand.sprite.getGlobalBounds())) {
                ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWSCONTOUR.png");
            }
            else {
                ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWS.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(Haider.sprite.getGlobalBounds())) {
             //   Haider.texture.loadFromFile("sprites\\npc\\HaiderLohContour.png");
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)  ) {
                    
                    
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)  ) {
                  
                   
                }
            }
            else {
                Haider.texture.loadFromFile("sprites\\npc\\HaiderLoh.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(NPCPlohoiParen.sprite.getGlobalBounds())) {
                NPCPlohoiParen.texture.loadFromFile("sprites\\npc\\PlohoiParenContour.png");
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && fightmenu1.getOpen() == false) {
                    player1.intimestopdio = true;
                    fightmenu1.OpenMenu(PlohoiParen);

                }

            }
            else {
                NPCPlohoiParen.texture.loadFromFile("sprites\\npc\\PlohoiParen.png");
            }
            if (dayAndNight.getNight() == true) {
                if (player1.sprite.getGlobalBounds().intersects(NPCDIO.sprite.getGlobalBounds())) {
                    NPCDIO.texture.loadFromFile("sprites\\npc\\PlohoiParenContour.png");
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && fightmenu1.getOpen() == false) {
                        player1.intimestopdio = true;
                        fightmenu1.OpenMenu(DIO);

                    }

                }
                else {
                    NPCDIO.texture.loadFromFile("sprites\\npc\\PlohoiParen.png");
                }
            }
            
            if (player1.sprite.getGlobalBounds().intersects(Shop.sprite.getGlobalBounds())) {
                Shop.texture.loadFromFile("sprites\\map\\ShopCONTOUR.png");
              
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                    ShopTutorial.setOpen(true);
                }
            }
            else {
                Shop.texture.loadFromFile("sprites\\map\\Shop.png");
            }

           

        }
        if (player1.stand != 4 || playerstand.visible == false) {
            isEmeraldSplash = false;
            EmeraldSplashsound.stop();
        }

        //квесты
        
        if (dayAndNight.getNight() == true) {
            Bonfire.texture.loadFromFile("sprites\\map\\BonfireOn.png");
       }
        else{
            Bonfire.texture.loadFromFile("sprites\\map\\BonfireOff.png");
        }

        if (AerosmithHbutton == true && Hbuttontime.getElapsedTime().asMilliseconds() < 100) {
           
                AerosmithHButtonSound.play();
    
        }
        if (player1.attacking == true) {
            if (player1.FightTech == 1) {
                sf::Vector2f pos = player1.sprite.getPosition();
                sf::FloatRect bounds = player1.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f - 44.f,	pos.y + bounds.height / 2.f };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f,	pos.y + bounds.height / 2.f };
                }
                SteelBall* steelballs = new SteelBall(posCenter, player1,teststeelballscharge);
                SteelBallsPlayerSprites.push_back(steelballs);  
            }
            player1.attacking = false;
        }



        if (isTimeStopped == true && timestop.getElapsedTime().asSeconds() < 10.f) {
            if (hsh == 0) {
                timestopsound.play();
                hsh = 1;
            }
            timestoppower.visible = true;
        }
        if (isTimeStopped == true && timestop.getElapsedTime().asSeconds() > 10.f) {
            isTimeStopped = false;
            timeresumesound.play();
            timestoppower.visible = false;
            hsh = 0;
        }
        if (isMandomTime == false && MandomTime.getElapsedTime().asSeconds() > 6.f) {
            if (player1.stand == 2) {
                MandomClockEndsound.play();
            }
            MandomTime.restart();
            MandomX = player1.sprite.getPosition().x;
            MandomY = player1.sprite.getPosition().y;
            MandomViewX = view.getCenter().x;
            MandomViewY = view.getCenter().y;
            MandomHealth = player1.health;

        }
        if (isWrOxy == true && WROxy.getElapsedTime().asSeconds() <= 1) {
            WrOxyImage.sprite.setPosition(playerstand.sprite.getPosition());
            WrOxyImage.visible = true;
        }




        MandomClock(MandomTime, MandomClockHUD);

        for (auto dimensionClones : DimensionClonesSprites) {
            DimensionClonesDamage(*dimensionClones, DimensionClonesSprites);
        }
        for (auto steelballs : SteelBallsPlayerSprites) {
            SteelBallsDamage(*steelballs, SteelBallsPlayerSprites, YopAngelo);
        }
    
        for (auto laser : laserSprites) {
            LaserDamage(*laser, laserSprites, YopAngelo);
        }
        for (auto barragehands : BarrageHandsSprites) {
            barragehands->update();
        }
        for (auto bubles : BublesSprites) {
            BublesDamage(*bubles, BublesSprites, YopAngelo);
        }
        for (auto barragehands : BarrageHandsSprites) {
            DeleteBarrageHands(*barragehands, BarrageHandsSprites);
        }
        for (auto aerosmithBullet : AerosmithBulletsSprites) {
           
            AerosmithBulletsDamage(*aerosmithBullet, AerosmithBulletsSprites, YopAngelo);
        }
        for (auto steelballs : SteelBallsPlayerSprites) {
            steelballs->update(time);
        }

    
     

        WrOxyDamagePl(WrOxyImage, player1, time);
        WrOxyDamageVragov(WrOxyImage, YopAngelo, time);
        if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asMilliseconds() > EmeraldSplashTmAttack) {
            sf::Vector2f pos = playerstand.sprite.getPosition();
            sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
            sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
            if (player1.left == true) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2 - 44,	pos.y + bounds.height / 2 };
            }
            if (player1.left == false) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
            }

            Laser* laser = new Laser(posCenter, player1,time);
            laserSprites.push_back(laser);
            EmeraldSplashTmAttack += 450.f;

        }
        if (AerosmithHbutton == true && Hbuttontime.getElapsedTime().asSeconds() <= 10  && Hbuttontime.getElapsedTime().asMilliseconds() >= AerosmithHTmAttack) {
            sf::Vector2f pos = playerstand.sprite.getPosition();
            sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
            sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
            if (player1.left == true) {
                posCenter = sf::Vector2f{ pos.x  ,	pos.y + bounds.height / 2 };
            }
            if (player1.left == false) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
            }

            AerosmithBullet* aerosmithbullet = new AerosmithBullet(posCenter, player1);
            AerosmithBulletsSprites.push_back(aerosmithbullet);
            AerosmithHTmAttack += 50.f;

        }
        if (AerosmithHbutton == true && Hbuttontime.getElapsedTime().asSeconds() >= 7 || AerosmithHbutton == false) {
            AerosmithHbutton = false;
            AerosmithHTmAttack = 100.f;
        }
        if (SAWBublCreate == true) {
            sf::Vector2f pos = playerstand.sprite.getPosition();
            sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
            sf::Vector2f posCenter = sf::Vector2f{ 0.f,	0.f };
            if (player1.left == true) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2 - 44,	pos.y + bounds.height / 2 };
            }
            if (player1.left == false) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
            }

            Bubles* bubles = new Bubles(posCenter, player1, time);
            BublesSprites.push_back(bubles);
            SAWBublCreate = false;
        }
        if (GeTreeSpawn == true) {
            sf::Vector2f pos;
            if (player1.left == true) {
                pos = { player1.sprite.getPosition().x,  player1.sprite.getPosition().y - player1.sprite.getGlobalBounds().height };
            }
            else  if (player1.left == false) {
                pos = { player1.sprite.getPosition().x + player1.sprite.getGlobalBounds().width + 2.f, player1.sprite.getPosition().y - player1.sprite.getGlobalBounds().height };
            }

            GeTree* getree = new GeTree(pos,player1.left);
            GeTreeSprites.push_back(getree);
            GeTreeSpawn = false;
            GeTreeSummonSound.play();
        }
        if (KqCoinSpawn == true) {
            sf::Vector2f pos = player1.sprite.getPosition();
          
            

            if (player1.left == true) {
                pos = sf::Vector2f{ pos.x - player1.sprite.getGlobalBounds().width,	pos.y + player1.sprite.getGlobalBounds().height};
            }
            if (player1.left == false) {
                pos = sf::Vector2f{ pos.x + player1.sprite.getGlobalBounds().width,	pos.y + player1.sprite.getGlobalBounds().height };
            }

            KqCoins* kqcoins = new KqCoins(pos, player1, time);
            KqCoinsSprites.push_back(kqcoins);
            KqCoinSpawn = false;
        }
        if (TheWorldKniveSpawn == true) {
            sf::Vector2f pos = playerstand.sprite.getPosition();
            sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
            sf::Vector2f posCenter = sf::Vector2f{ 0.f,	0.f };
            if (player1.left == true) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f - 44,	pos.y + bounds.height / 2.f };
            }
            if (player1.left == false) {
                posCenter = sf::Vector2f{ pos.x + bounds.width / 2.f,	pos.y + bounds.height / 2.f };
            }

            TheWorldKnive* theworldknive = new TheWorldKnive(posCenter, player1);
            TheWorldKnivesSprites.push_back(theworldknive);
            TheWorldKniveSpawn = false;
        }
        if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asMilliseconds() < 400.f) {
            EmeraldSplashsound.play();

        }
        if (isEmeraldSplash == true && EmeraldSplashTm.getElapsedTime().asSeconds() > 10.f) {
            isEmeraldSplash = false;

            EmeraldSplashTmAttack = 450.f;
        }
        if (D4CDimensionClones == true) {
            sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
            StandBounds.width += 50.f;
            sf::Vector2f pos = playerstand.sprite.getPosition();
            if (StandBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
                DimensionClones* dimensionClones = new DimensionClones(pos, YopAngelo);
                DimensionClonesSprites.push_back(dimensionClones);
                D4CDimensionClones = false;
            }
        }
        if (GeSoulPunch == true) {
            sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
            StandBounds.width += 30.f;
            sf::Vector2f pos = YopAngelo.sprite.getPosition();
            if (StandBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
               GeSoul* GeSouls = new GeSoul(pos, YopAngelo);
               GeSoulSprites.push_back(GeSouls);
                GeSoulPunch = false;
            }
        }
        if (SheertHeartAttackSpawn == true) {
            sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
            StandBounds.width += 50.f;
            sf::Vector2f pos = { playerstand.sprite.getPosition().x, playerstand.sprite.getPosition().y + playerstand.sprite.getGlobalBounds().height };
            if (StandBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
                SheerHeartAttack* SheerHeartAttacks = new SheerHeartAttack(pos, YopAngelo);
                SheerHeartAttackSprites.push_back(SheerHeartAttacks);
                SheertHeartAttackSpawn = false;
            }
        }
        if (WsDiscSpawn == true) {
            sf::FloatRect StandBounds = playerstand.sprite.getGlobalBounds();
            StandBounds.width += 50.f;
            sf::Vector2f pos = { playerstand.sprite.getPosition().x, playerstand.sprite.getPosition().y + playerstand.sprite.getGlobalBounds().height };
            if (StandBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
                WsDisc* WsDiscs = new  WsDisc(YopAngelo);
                WsDiscSprites.push_back(WsDiscs);
                WsDiscSpawn = false;
                
            }
        }

        if (CmoonRotateSpawn == true) {
            CmoonRotateSpawn = false;
            playerCmoonRotate.Activate();
        }
        if (WsAcidSpawn == true) {
           
                WsAcidCloud* WsAcidClouds = new  WsAcidCloud(YopAngelo,playerstand);
                WsAcidCloudSprites.push_back(WsAcidClouds);
                WsAcidSpawn = false;
          
        }
        if (AngeloZiv == true && YopAngelo.health <= 0.f) {
            AngeloZiv = false;
            AngeloLife.restart();
        }
        if (AngeloLife.getElapsedTime().asSeconds() > 30.f && AngeloZiv == false) {
            AngeloZiv = true;
            YopAngelo.health = 100.f;
            YopAngelo.sprite.setPosition({ 2377.f, 1064.f });
        }
        if (playerstand.barrage == true) {

            sf::Vector2f pos = playerstand.sprite.getPosition();
            BarrageHands* barragehands = new BarrageHands(pos, player1);
            BarrageHandsSprites.push_back(barragehands);

        }
        if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asSeconds() >= 5.f && player1.stand != 5) {
            playerstand.barrage = false;
        }
        else if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asSeconds() >= 3.f && player1.stand == 5) {
            playerstand.barrage = false;
        }
        if (WROxy.getElapsedTime().asSeconds() > 10.f) {
            isWrOxy = false;
            WrOxyImage.visible = false;
        }
        if (isMandomTime == true) {
            MandomTimesound.play();
            MandomTime.restart();
            view.setCenter(MandomViewX, MandomViewY);
            player1.sprite.setPosition(MandomX, MandomY);
            playerstand.sprite.setPosition(MandomX, MandomY);
            player1.health = MandomHealth;
            isMandomTime = false;

        }
        //жизни
        if (D4CDimension == true && Gbuttontime.getElapsedTime().asMilliseconds() <= 100) {
            D4CDimensionhopsound.play();
        }
        if (YopAngelo.health > 90.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth10.png");
        }
        else  if (YopAngelo.health > 80.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth9.png");
        }
        else  if (YopAngelo.health > 70.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth8.png");
        }
        else  if (YopAngelo.health > 60.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth7.png");
        }
        else  if (YopAngelo.health > 50.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth1.png");
        }
        else  if (YopAngelo.health > 40.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth6.png");
        }
        else  if (YopAngelo.health > 30.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth5.png");
        }
        else  if (YopAngelo.health > 20.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth4.png");
        }
        else  if (YopAngelo.health > 10.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth3.png");
        }
        else  if (YopAngelo.health > 0.f) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth2.png");
        }


       
        BarrageDamage(YopAngelo, time, player1, playerstand);
        PlayerUpdate(player1, PLAYER1LEFT_FILE_NAME, "sprites\\player\\player1rightmove1.png", "sprites\\player\\player1leftmove1.png", PLAYER1RIGHT_FILE_NAME, playerstand, time);
        AuraUpdate(plAura, player1, playerstand, time);
        playerAura.update();
        Powersbjupdate(timestoppower, { player1.sprite.getPosition().x - 370, player1.sprite.getPosition().y - 425 }, 1);
        
        StandUpdate(playerstand, player1, time);
        CheckCollisNPC(Haider, player1);
        CheckCollisNPC(NPCPlohoiParen, player1);
        CheckCollisVragi(YopAngelo, player1);
        CheckCollisMap(House, player1);
        CheckCollisMap(Shop, player1);
        CheckCollisMap(Bonfire, player1);
        if (player1.health <= 0) {
            GameOverOn = true;

        }


      
        view.setCenter(player1.sprite.getPosition());
      
       
        textgoap = 0.f;
        for (auto Notificationstext : NotificationsTexts) {
            Notificationstext->update({ view.getCenter().x + 400.f,view.getCenter().y - 300.f }, textgoap);
            textgoap += 30.f;
        }
        for (auto Notificationstext : NotificationsTexts) {
            NotificationsDie(*Notificationstext, NotificationsTexts);
        }
       
        hpbar.update(view.getCenter(), player1,fightmenu1.getFight());

        VersionText.setPosition(view.getCenter().x - 950, view.getCenter().y + 450);
      
        if (D4CDimension == false) {
            VragiUpdate(YopAngelo,VragStand ,player1, time);
        }
        if (Hbuttontime.getElapsedTime().asSeconds() >= 10 && D4CDimensionClones == true) {
            D4CDimensionClones = false;
        }
        HUDobjupdate(AngeloHealth, { YopAngelo.sprite.getPosition().x - 35, YopAngelo.sprite.getPosition().y - 40 }, 1);
        
        Mapbjupdate(House);
        Mapbjupdate(Map1);
        Mapbjupdate(ArrowSand);
        Mapbjupdate(Shop);

        PlayerInventory.update({ view.getCenter().x + 24, view.getCenter().y + 136}, { view.getCenter().x - 234, view.getCenter().y + 100 },player1,pos,laungag);
        InvPR1.update({ view.getCenter().x + 800, view.getCenter().y - 400 });
        HUDobjupdate(MandomClockHUD, { view.getCenter().x + 800, view.getCenter().y + 350 }, 1);
     
        for (auto laser : laserSprites) {
            laser->update();
        }
        for (auto aerosmithBullet : AerosmithBulletsSprites) {
            aerosmithBullet->update(time);
        }
        for (auto bubles : BublesSprites) {
            bubles->update();
        }
        for (auto gesoul : GeSoulSprites) {
            gesoul->update(*gesoul,time);
        }
        for (auto gesoul : GeSoulSprites) {
            GeSoulDamage(*gesoul, GeSoulSprites);
        }
        for (auto theworldknives : TheWorldKnivesSprites) {
            theworldknives->update(time,timestoppower);
        }
        for (auto theworldknives : TheWorldKnivesSprites) {
            TheWorldKnivesDamage(*theworldknives, TheWorldKnivesSprites, YopAngelo);
        }
        for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
            SheerHeartAttacks->update(time);
        }
        for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
            SheerHeartAttackDamage(*SheerHeartAttacks, SheerHeartAttackSprites);
        }
        for (auto GeTree : GeTreeSprites) {
            GeTree->update(*GeTree,time,YopAngelo);
        }
      
        for (auto GeTree : GeTreeSprites) {
            GeTreesDamage(*GeTree, GeTreeSprites);
        }
        cheats.update(player1);

        for (auto kqcoins : KqCoinsSprites) {
            kqcoins->update();
            }
        for (auto kqcoins : KqCoinsSprites) {
            KqCoinsDamage(*kqcoins, KqCoinsSprites, YopAngelo);
        }
        for (auto WsAcid : WsAcidCloudSprites) {
            WsAcid->update(playerstand, YopAngelo);
        }
        for (auto WsAcid : WsAcidCloudSprites) {
            WsAcidCloudDamage(*WsAcid, WsAcidCloudSprites);
        }
        for (auto WsDisc : WsDiscSprites) {
            WsDisc->update();
        }
        for (auto WsDisc : WsDiscSprites) {
            WsDiscDamage(*WsDisc, WsDiscSprites);
        }
        fightmenu1.update({ view.getCenter().x - 205.5f, view.getCenter().y - 250.f },pos,player1,playerstand, VragStand, player1.sprite.getPosition(), laungag);
        if (D4CDimension == true && Gbuttontime.getElapsedTime().asSeconds() >= 20) {
            D4CDimension = false;
        }
        if (D4CDimension == true && player1.stand != 6) {
            D4CDimension = false;
        }
       
            playerCmoonRotate.update(YopAngelo,view);
     
        window.setView(view);
        window.clear(Goluboi);
      
        MapObjectsDraw(window, Map1);
        MapObjectsDraw(window, ArrowSand);
        MapObjectsDraw(window, House);
        MapObjectsDraw(window, Shop);
        MapObjectsDraw(window, Bonfire);
        if (D4CDimension == false) {
            VragiDraw(window, YopAngelo);
            NPCDraw(window, Haider);
            NPCDraw(window, NPCPlohoiParen);
            if (dayAndNight.getNight() == true) {
                NPCDraw(window, NPCDIO);
            }
           
        }
        for (auto dimensionClones : DimensionClonesSprites) {
            window.draw(dimensionClones->getSprite());
        }
      
        playerAura.draw(window);
        PlayerDraw(window, player1);
        for (auto laser : laserSprites) {
            window.draw(laser->getSprite());
        }
        for (auto barragehands : BarrageHandsSprites) {
            window.draw(barragehands->getSprite());
        }
        for (auto bubles : BublesSprites) {
            window.draw(bubles->getSprite());
        }
        for (auto steelballs : SteelBallsPlayerSprites) {
            steelballs->draw(window);
        }
        for (auto aerosmithBullet : AerosmithBulletsSprites) {
            aerosmithBullet->draw(window);
        }
        for (auto theworldknives : TheWorldKnivesSprites) {
            theworldknives->draw(window);
        }
        for (auto SheerHeartAttacks : SheerHeartAttackSprites) {
            SheerHeartAttacks->draw(window);
        }
        for (auto kqcoins : KqCoinsSprites) {
            kqcoins->draw(window);
        }
        for (auto GeTree : GeTreeSprites) {
            GeTree->draw(window);
        }
        for (auto gesoul : GeSoulSprites) {
            gesoul->draw(window);
        }
        
        StandDraw(window, playerstand);
        if (YopAngelo.health > 0 && D4CDimension == false) {
            HudDraw(window, AngeloHealth);

        }
       
        PowersObjectsDraw(window, timestoppower);
        PowersObjectsDraw(window, WrOxyImage);
        for (auto WsAcid : WsAcidCloudSprites) {
            WsAcid->draw(window);
        }
        for (auto WsDisc : WsDiscSprites) {
            WsDisc->draw(window);
        }
        if (player1.stand == 2) {
            HudDraw(window, MandomClockHUD);
        }
        for (auto Notificationstext : NotificationsTexts) {
            Notificationstext->draw(window);

        }
        ReloadBar1.update({ view.getCenter().x - 950.f , view.getCenter().y }, Hbuttontime, Gbuttontime, Barrageplayer, player1);
        ReloadBar1.draw(window, Hbuttontime, Gbuttontime,Barrageplayer );
       
        fightmenu1.draw(window);
        if (D4CDimension == false) {
            hpbar.Draw(window);
        }
        window.draw(VersionText);
        if (D4CDimension == false) {
            InvPR1.draw(window);
            PlayerInventory.draw(window);
        }
       
        cursor1.draw(window);
        dayAndNight.update({view.getCenter().x - 960.f,view.getCenter().y - 540.f });
        if (D4CDimension == false) {
            dayAndNight.draw(window);
        }
        window.display();
    }
    return 0;
}
