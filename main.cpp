#include "settings.h"

#define _WIN32_WINNT 0x0500
using namespace sf;


//RandomObjects arrow1;
sf::Clock vremya;
Player player1;
Map Map1;
Map FightBackground;
Languages laungag;
Map ArrowSand;

Stand playerstand;
Stand VragStand;

Powers timestoppower;
Powers Vragtimestoppower;

Powers WrOxyImage;
Vragi YopAngelo;
Vragi PlohoiParen;
HUD MandomClockHUD;
NPC Haider;
NPC NPCPlohoiParen;
InventoryPreview InvPR1;

Fights fightmenu1;
FightBackButton backbuttonfights;


Quests quest1;
Quests quest2;
HUD AngeloHealth;
VragiHealth fighthealth;

Aura plAura;
Aura VragAura;

CursorArrow cursor1;

PlayerHealth hpbar;
Map House;
Map Shop;
GameOver gameover1;
Inventory PlayerInventory;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    std::list<Laser*> laserSprites;
    std::list<Bubles*> BublesSprites;
    std::list<BarrageHands*> BarrageHandsSprites;
    std::list<DimensionClones*> DimensionClonesSprites;
    std::list<Notifications*> NotificationsTexts;
    setlocale(LC_ALL, "Russian");
   
    bool testrazrab = false;
    
    float MandomX = 0;
    float MandomY = 0;
    float MandomViewX = 0;
    float MandomViewY = 0;
    int MandomHealth = 0;
    float EmeraldSplashTmAttack = 450.f;
    float textgoap = 0.f;
    //меню

    sf::Image icon;
    icon.loadFromFile("icon.png");
    const sf::Uint8* pixels = icon.getPixelsPtr();

    LanguageFlags RU_FLAG;
    LanguageFlags USA_FLAG;
    LanguageFlagsInit(USA_FLAG, { 1000.f ,0.f}, "USA.png");
    LanguageFlagsInit(RU_FLAG, { 0.f,0 }, "RUSSIA.png");
    sf::Vector2i pixelPos;
    sf::Vector2f pos;
    Event eventda;
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
        else
        while (SelectLaungage.pollEvent(eventda)) {

            if (eventda.type == sf::Event::Closed) {
                SelectLaungage.close();
                return 0;
            }
        }
       
        SelectLaungage.clear();
        SelectLaungage.draw(RU_FLAG.sprite);
        SelectLaungage.draw(USA_FLAG.sprite);
        SelectLaungage.display();
    }

    Menu menu1(laungag);

    
    srand(time(NULL));
    Music music1;
    music1.openFromFile("music1.ogg");
    music1.play();
    music1.setVolume(30);
    music1.setLoop(true);
    Font font;
    font.loadFromFile("NjalBold.ttf");



    /* Music WRtheme;
    WRtheme.openFromFile("sounds\\themes\\WR_Theme.ogg");
    WRtheme.setVolume(10);
    WRtheme.setLoop(true);

    Music SAWtheme;
    SAWtheme.openFromFile("sounds\\themes\\SAW_Theme.ogg");
    SAWtheme.setVolume(10);
    SAWtheme.setLoop(true);
    */
    sf::SoundBuffer D4CDimensionhopbuffer;
    D4CDimensionhopbuffer.loadFromFile("sounds\\stands\\D4CDimensionHop.ogg");// тут загружаем в буфер что то
    sf::Sound D4CDimensionhopsound(D4CDimensionhopbuffer);

    sf::SoundBuffer EmeraldSplashBuffer;
    EmeraldSplashBuffer.loadFromFile("sounds\\stands\\EmeraldSplash.ogg");// тут загружаем в буфер что то
    sf::Sound EmeraldSplashsound(EmeraldSplashBuffer);

    sf::SoundBuffer standsummonbuffer;
    standsummonbuffer.loadFromFile("sounds\\stands\\stand_summon_sound.ogg");// тут загружаем в буфер что то
    sf::Sound standsummonsound(standsummonbuffer);

    sf::SoundBuffer timestopbuffer;
    timestopbuffer.loadFromFile("sounds\\stands\\The_WORLD_time-stop.ogg");// тут загружаем в буфер что то
    sf::Sound timestopsound(timestopbuffer);

    sf::SoundBuffer timeresumebuffer;
    timeresumebuffer.loadFromFile("sounds\\stands\\Time_Resume.ogg");// тут загружаем в буфер что то
    sf::Sound timeresumesound(timeresumebuffer);

    sf::SoundBuffer MandomTimebuffer;
    MandomTimebuffer.loadFromFile("sounds\\stands\\Mandom_sound1.ogg");// тут загружаем в буфер что то
    sf::Sound MandomTimesound(MandomTimebuffer);

    sf::SoundBuffer MandomClockEndbuffer;
    MandomClockEndbuffer.loadFromFile("sounds\\stands\\MandomClockEnd.ogg");// тут загружаем в буфер что то
    sf::Sound MandomClockEndsound(MandomClockEndbuffer);
    MandomClockEndsound.setVolume(50.f);

    sf::SoundBuffer TwBarragebuffer;
    TwBarragebuffer.loadFromFile("sounds\\stands\\The_World_Barrage.ogg");// тут загружаем в буфер что то
    sf::Sound TwBarragesound(TwBarragebuffer);

    sf::SoundBuffer SAWBarragebuffer;
    SAWBarragebuffer.loadFromFile("sounds\\stands\\SAWBarrage.ogg");// тут загружаем в буфер что то
    sf::Sound SAWBarragesound(SAWBarragebuffer);

    sf::SoundBuffer WRBarragebuffer;
    WRBarragebuffer.loadFromFile("sounds\\stands\\WRbarrage.ogg");// тут загружаем в буфер что то
    sf::Sound WRBarragesound(WRBarragebuffer);

    

    RenderWindow window(sf::VideoMode::getDesktopMode(), "Traveler's Bizzare Adventure",
        Style::Titlebar | Style::Close | Style::Fullscreen );
   

   

    window.setKeyRepeatEnabled(false);
 
  // window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    window.setIcon(icon.getSize().x, icon.getSize().y, pixels);




    sf::View view(sf::FloatRect(0.f, 0.f, WINDOW_X, WINDOW_Y));
    view.setCenter(player1.sprite.getPosition()); // устанавливаем центр камеры на игрока
    window.setView(view);
 //   sf::Vector2f position(player1.sprite.getPosition());
    NPCInit(Haider, "sprites\\npc\\HaiderLoh.png", { 1578 ,360 });
    NPCInit(NPCPlohoiParen, "sprites\\npc\\PlohoiParen.png", { 2967, 412 });

    HudInit(MandomClockHUD, "sprites\\hud\\MandomClock1.png");
   // HudInit(InventoryArrow, "sprites\\hud\\ARROW.png");
    HudInit(AngeloHealth, "sprites\\hud\\angeloHealth10.png");

    VragiInit(YopAngelo, "sprites\\npc\\YoAngelo.png", 0, 100.f,{ 2377,1064 }, true,"Yo Angelo",0);
    VragiInit(PlohoiParen, "sprites\\npc\\PlohoiParenLeft.png", 1, 100.f, { 0,0 }, false, "Bad Guy", 1000);

    PowrsObjectsINIT(timestoppower, "sprites\\powers\\TimeStop.png");
    PowrsObjectsINIT(Vragtimestoppower, "sprites\\powers\\TimeStop.png");
    PowrsObjectsINIT(WrOxyImage, "sprites\\powers\\WRoxygen.png");

    StandInit(playerstand, "sprites\\stands\\THE_WORLD_RIGHT.png");
    StandInit(VragStand, "sprites\\stands\\THE_WORLD_RIGHT.png");
    // RandomObjectsINIT(arrow1, ARROW_FILE_NAME); 
    PlayerInit(player1, PLAYER1RIGHT_FILE_NAME);
   
    MapObjectsINIT(FightBackground, "sprites\\map\\FightBackgroundTest.png", { -480.f,423.f });
  
    MapObjectsINIT(Map1, "sprites\\map\\MAP.png", { 0,0 });
    MapObjectsINIT(ArrowSand, "sprites\\map\\SANDARROWS.png", { 1567,1654 });
    MapObjectsINIT(House, "sprites\\map\\House.png", { 851,580 });
    MapObjectsINIT(Shop, "sprites\\map\\Shop.png", {504.f,807.f});

    QuestsInit(quest1, "sprites\\quests\\quest1.png");
    QuestsInit(quest2, "sprites\\quests\\quest2.png");

    

    AuraInit(plAura, "sprites\\stands\\auras\\TwAuraFrame1.png");
    AuraInit(VragAura, "sprites\\stands\\auras\\TwAuraFrame1.png");
   
   

    //  Text HealthAngeloTest(std::to_string(YopAngelo.health), font, 160);
    Text VersionText(VERSION_NAME, font, 50);
   // Text ArrowKolInv(std::to_string(ArrowInv), font, 40);
   // ArrowKolInv.setFillColor(sf::Color::Black);
    if (testrazrab == true) {
      //  std::cin >> player1.stand;
    }
    float time;
    while (window.isOpen()) {
       

        time = vremya.getElapsedTime().asMicroseconds();
        vremya.restart();
        time = time / 800.f;
         pixelPos = sf::Mouse::getPosition(window);
         pos = window.mapPixelToCoords(pixelPos);
        Event event;

        while (MenuOn == true) {
            view.setCenter(960, 540);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);

            menu1.update(pos, window, "saves\\auto_save.txt", view, player1, quest1, quest2, player1.sprite.getPosition().y, player1.sprite.getPosition().x, player1.health);

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
            view.setCenter(960, 540);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            gameover1.update(window, pos, "saves\\auto_save.txt", view, player1, quest1, quest2, player1.sprite.getPosition().y, player1.sprite.getPosition().x, player1.health);
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
        backbuttonfights.restartClock();
        while (fightmenu1.getFight() == true) {
            if (MandomX >= 1920.f || MandomX <= 0.f) {
                MandomX = 900.f;
            }
            if (MandomY > 840.f || MandomY < 840.f) {
                MandomY = 840.f;
            }
            time = vremya.getElapsedTime().asMicroseconds();
            vremya.restart();
            time = time / 800.f;
            sf::View view(sf::FloatRect(0.f, 0.f, 960, 540));
            view.setCenter(player1.sprite.getPosition().x + 22, player1.sprite.getPosition().y - 50.f);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            if (fightmenu1.getVrag()->health <= 0) {
                player1.money += fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.stoi = false;
            }
          
            if (player1.health <= 0.f) {
                player1.money -= fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                player1.health = 1.f;
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.stoi = false;
            }
            VragiAuraUpdate(VragAura, *fightmenu1.getVrag(), VragStand, time);
            AuraUpdate(plAura, player1, playerstand, time);
            fighthealth.update({ view.getCenter().x + 350.f - fighthealth.getSprite().getGlobalBounds().width , view.getCenter().y - 250.f }, *fightmenu1.getVrag());
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
            backbuttonfights.update({ view.getCenter().x + 350.f, view.getCenter().y + 250.f - backbuttonfights.getSprite().getGlobalBounds().height }, pos);
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
            AuraDraw(window, VragAura);
            for (auto laser : laserSprites) {
                laser->update();
            }
            for (auto bubles : BublesSprites) {
                bubles->update();
            }
            PlayerDraw(window, player1);
            fighthealth.Draw(window);
            StandDraw(window, playerstand);
            StandDraw(window, VragStand);
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
                MandomViewX = view.getCenter().x;
                MandomViewY = view.getCenter().y;
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

                player1.stoi = true;
            }
            if (player1.stoi == true && VragIsTimeStopped == false) {
                player1.stoi = false;
            }
            MandomClock(MandomTime, MandomClockHUD);

            for (auto dimensionClones : DimensionClonesSprites) {
                DimensionClonesDamage(*dimensionClones, DimensionClonesSprites);
            }
            for (auto laser : laserSprites) {
                LaserDamage(*laser, laserSprites, *fightmenu1.getVrag());
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
            if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asMilliseconds() < 200) {

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
            }
            hpbar.update(view.getCenter(), player1, fightmenu1.getFight());
            if (SAWBublCreate == true) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
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
                if (StandBounds.intersects(fightmenu1.getVrag()->sprite.getGlobalBounds())) {
                    DimensionClones* dimensionClones = new DimensionClones(pos, *fightmenu1.getVrag());
                    DimensionClonesSprites.push_back(dimensionClones);
                    D4CDimensionClones = false;
                }
            }


            if (playerstand.barrage == true) {

                sf::Vector2f pos = playerstand.sprite.getPosition();
                BarrageHands* barragehands = new BarrageHands(pos, player1);
                BarrageHandsSprites.push_back(barragehands);

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
                view.setCenter(MandomViewX, MandomViewY);
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
            for (auto bubles : BublesSprites) {
                window.draw(bubles->getSprite());
            }

            PowersObjectsDraw(window, Vragtimestoppower);
            PowersObjectsDraw(window, timestoppower);
            PowersObjectsDraw(window, WrOxyImage);
            if (player1.stand == 2) {
                HudDraw(window, MandomClockHUD);
            }
      
            hpbar.Draw(window);
            backbuttonfights.draw(window);
            cursor1.draw(window);
            if (backbuttonfights.getClose() == true && backbuttonfights.getValidSur() == true) {
                backbuttonfights.setClose(false);
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.stoi = false;
            }
            else  if (backbuttonfights.getClose() == true) {
                backbuttonfights.setClose(false);
                player1.money -= fightmenu1.getVrag()->Reward;
                fightmenu1.setFight(false);
                player1.sprite.setPosition(fightmenu1.getPos());
              
                playerstand.visible = false;
                playerstand.sprite.setPosition(fightmenu1.getPos());
                playerstand.barrage = false;
                player1.stoi = false;
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
                else if (rand() % 5 == 1) {
                    Notifications* Notificationstext = nullptr;

                    if (PlayerInventory.ItemCanBeAdded(4)) {
                        if (laungag.EnglishText == true) {
                            Notificationstext = new Notifications(L"+ Food");
                        }
                        else if (laungag.RussiaText == true) {
                            Notificationstext = new Notifications(L"+ Еда");
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
            }

            /*  else  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::U) {
                   saveGame(player1, quest1, quest2, player1.sprite.getPosition().x, player1.sprite.getPosition().y);
               }

               else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::I) {
                   loadGame(player1, quest1, quest2, player1.sprite.getPosition().y, player1.sprite.getPosition().x);

               }*/
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::T && AttackTm.getElapsedTime().asSeconds() > 1 && playerstand.barrage == false) {
                AttackTm.restart();
                player1.attacking = true;
            }
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


        if (playerstand.barrage == true && Barrageplayer.getElapsedTime().asMilliseconds() < 200) {

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
        }



        if (D4CDimension == false) {

            if (player1.sprite.getGlobalBounds().intersects(ArrowSand.sprite.getGlobalBounds())) {
                ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWSCONTOUR.png");
            }
            else {
                ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWS.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(Haider.sprite.getGlobalBounds())) {
                Haider.texture.loadFromFile("sprites\\npc\\HaiderLohContour.png");
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && quest1.done == false) {
                    quest1.active = true;
                    
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && quest1.done == true && quest2.done == false) {
                    quest2.active = true;
                   
                }
            }
            else {
                Haider.texture.loadFromFile("sprites\\npc\\HaiderLoh.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(NPCPlohoiParen.sprite.getGlobalBounds())) {
                NPCPlohoiParen.texture.loadFromFile("sprites\\npc\\PlohoiParenContour.png");
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && fightmenu1.getOpen() == false) {
                    player1.stoi = true;
                    fightmenu1.OpenMenu(PlohoiParen);

                }

            }
            else {
                NPCPlohoiParen.texture.loadFromFile("sprites\\npc\\PlohoiParen.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(Shop.sprite.getGlobalBounds())) {
                Shop.texture.loadFromFile("sprites\\map\\ShopCONTOUR.png");
            }
            else {
                Shop.texture.loadFromFile("sprites\\map\\Shop.png");
            }

            if (player1.sprite.getGlobalBounds().intersects(Haider.sprite.getGlobalBounds())) {
                Haider.texture.loadFromFile("sprites\\npc\\HaiderLohContour.png");
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && quest1.done == false) {
                    quest1.active = true;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && quest1.done == true && quest2.done == false) {
                    quest2.active = true;
                }
            }
            else {
                Haider.texture.loadFromFile("sprites\\npc\\HaiderLoh.png");
            }

        }
        if (player1.stand != 4 || playerstand.visible == false) {
            isEmeraldSplash = false;
            EmeraldSplashsound.stop();
        }

        //квесты

        if (player1.stand > 0 && quest1.done == false) {
            quest1.active = false;
            quest1.done = true;
            //saveGame("saves\\auto_save.txt", player1, quest1, quest2, player1.sprite.getPosition().x, player1.sprite.getPosition().y, player1.health, view.getCenter().x, view.getCenter().y);
        }
        if (YopAngelo.health <= 0 && quest2.done == false) {
            quest2.active = false;
            quest2.done = true;
            //saveGame("saves\\auto_save.txt", player1, quest1, quest2, player1.sprite.getPosition().x, player1.sprite.getPosition().y, player1.health, view.getCenter().x, view.getCenter().y);

        }

        if (AttackTm.getElapsedTime().asMilliseconds() > 500 && player1.attacking == true) {
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
        if (SAWBublCreate == true) {
            sf::Vector2f pos = playerstand.sprite.getPosition();
            sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
            sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
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


        if (playerstand.barrage == true) {

            sf::Vector2f pos = playerstand.sprite.getPosition();
            BarrageHands* barragehands = new BarrageHands(pos, player1);
            BarrageHandsSprites.push_back(barragehands);

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
        if (YopAngelo.health > 90) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth10.png");
        }
        else  if (YopAngelo.health > 80) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth9.png");
        }
        else  if (YopAngelo.health > 70) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth8.png");
        }
        else  if (YopAngelo.health > 60) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth7.png");
        }
        else  if (YopAngelo.health > 50) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth6.png");
        }
        else  if (YopAngelo.health > 40) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth5.png");
        }
        else  if (YopAngelo.health > 30) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth4.png");
        }
        else  if (YopAngelo.health > 20) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth3.png");
        }
        else  if (YopAngelo.health > 10) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth2.png");
        }
        else  if (YopAngelo.health > 0) {
            AngeloHealth.texture.loadFromFile("sprites\\hud\\angeloHealth1.png");
        }

        if (player1.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds()) && player1.attacking == true) {
            if (player1.FighTech == 1) {
                YopAngelo.health = YopAngelo.health - 0.1;
            }
        }


        BarrageDamage(YopAngelo, time, player1, playerstand);
        PlayerUpdate(player1, PLAYER1LEFT_FILE_NAME, "sprites\\player\\player1rightmove1.png", "sprites\\player\\player1leftmove1.png", PLAYER1RIGHT_FILE_NAME, playerstand, time);
        AuraUpdate(plAura, player1, playerstand, time);
        Powersbjupdate(timestoppower, { player1.sprite.getPosition().x - 370, player1.sprite.getPosition().y - 425 }, 1);
        
        //RandomObjupdate(window.getSize().x, window.getSize().y, arrow1);
        StandUpdate(playerstand, player1, time);
        CheckCollisNPC(Haider, player1);
        CheckCollisNPC(NPCPlohoiParen, player1);
        CheckCollisVragi(YopAngelo, player1);
        CheckCollisMap(House, player1);
        CheckCollisMap(Shop, player1);
        /* if (player1.sprite.getGlobalBounds().intersects(arrow1.sprite.getGlobalBounds()) && arrow1.visible == true) {

             player1.stand = rand() % 2 + 1;

             if (player1.stand == 0) {
                 playerstand.visible = false;
            }
             arrow1.visible = false;
         }
         */

         // HealthAngeloTest.setString(std::to_string(YopAngelo.health));
        if (player1.health <= 0) {
            GameOverOn = true;

        }


     /*   sf::Vector2f target(player1.sprite.getPosition()); // целевая позиция камеры
        sf::Vector2f direction = target - position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (distance > 1.f) // если расстояние между текущей и целевой позициями больше 1 пикселя
        {
            sf::Vector2f unit_direction = direction / distance;
            float pixels_to_move = 0.25f * time;
            pixels_to_move = std::min(pixels_to_move, distance);
            sf::Vector2f movement = unit_direction * pixels_to_move;
            position += movement;
            view.setCenter(position);
           
        }
    */
        
        view.setCenter(player1.sprite.getPosition());
        textgoap = 0.f;
        for (auto Notificationstext : NotificationsTexts) {
            Notificationstext->update({ view.getCenter().x + 400.f,view.getCenter().y - 300.f }, textgoap);
            textgoap += 30.f;
        }
        for (auto Notificationstext : NotificationsTexts) {
            NotificationsDie(*Notificationstext, NotificationsTexts);
        }
        // HealthAngeloTest.setPosition(view.getCenter().x - 965, view.getCenter().y - 565);
        hpbar.update(view.getCenter(), player1,fightmenu1.getFight());

        VersionText.setPosition(view.getCenter().x - 950, view.getCenter().y + 450);
        Questsupdate(quest1, { view.getCenter().x - 970, view.getCenter().y - 370 });
        Questsupdate(quest2, { view.getCenter().x - 970, view.getCenter().y - 370 });
        if (D4CDimension == false) {
            VragiUpdate(YopAngelo,VragStand ,player1, time);
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
        for (auto bubles : BublesSprites) {
            bubles->update();
        }
        if (menu1.getViewMenu() == true) {
            menu1.setViewMenu(false);
            if (menu1.getViewPos().x == 124673712485187.f && menu1.getViewPos().y == 124673712485187.f) {
                view.setCenter(gameover1.getViewPos());
            }
            else { view.setCenter(menu1.getViewPos().x, menu1.getViewPos().y); }
   
        }
        if (gameover1.getViewMenu() == true) {
            gameover1.setViewMenu(false);
            view.setCenter(gameover1.getViewPos());
            
        }
        fightmenu1.update({ view.getCenter().x - 205.5f, view.getCenter().y - 250.f },pos,player1,playerstand, VragStand, player1.sprite.getPosition(), laungag);
        if (D4CDimension == true && Gbuttontime.getElapsedTime().asSeconds() >= 20) {
            D4CDimension = false;
        }
        if (D4CDimension == true && player1.stand != 6) {
            D4CDimension = false;
        }
        cursor1.update(pos);
        window.setView(view);
        window.clear(Goluboi);
      
        MapObjectsDraw(window, Map1);
        MapObjectsDraw(window, ArrowSand);
        MapObjectsDraw(window, House);
        MapObjectsDraw(window, Shop);
        //RandomObjectsDraw(window, arrow1);
        if (D4CDimension == false) {
            VragiDraw(window, YopAngelo);
            NPCDraw(window, Haider);
            NPCDraw(window, NPCPlohoiParen);
        }
        for (auto dimensionClones : DimensionClonesSprites) {
            window.draw(dimensionClones->getSprite());
        }
        AuraDraw(window, plAura);
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
        StandDraw(window, playerstand);
        if (YopAngelo.health > 0 && D4CDimension == false) {
            HudDraw(window, AngeloHealth);

        }
        PowersObjectsDraw(window, timestoppower);
        PowersObjectsDraw(window, WrOxyImage);
        if (player1.stand == 2) {
            HudDraw(window, MandomClockHUD);
        }
        for (auto Notificationstext : NotificationsTexts) {
            Notificationstext->draw(window);

        }

      
        QuestsDraw(window, quest1);
        QuestsDraw(window, quest2);
        fightmenu1.draw(window);
        if (D4CDimension == false) {
            hpbar.Draw(window);
        }
        window.draw(VersionText);

        //  window.draw(HealthAngeloTest);
        if (D4CDimension == false) {
            InvPR1.draw(window);
            PlayerInventory.draw(window);
        }
        cursor1.draw(window);

    
        window.display();
    }
    return 0;
}
