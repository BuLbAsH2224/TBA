#include "settings.h"
using namespace sf;


//RandomObjects arrow1;

Player player1;
Map Map1;
Map ArrowSand;
Stand playerstand;
Powers timestoppower;
Powers WrOxyImage;
Vragi YopAngelo;
HUD MandomClockHUD;
NPC Haider;
HUD InventoryArrow;
Quests quest1;
Quests quest2;
HUD AngeloHealth;
Aura plAura;
int main() {
    std::list<Laser*> laserSprites;
    std::list<Bubles*> BublesSprites;
    std::list<BarrageHands*> BarrageHandsSprites;
    setlocale(LC_ALL, "Russian");
    bool testrazrab = false;
    int hsh = 0;
    float MandomX = 0;
    float MandomY = 0;
    float MandomViewX = 0;
    float MandomViewY = 0;
    int MandomHealth = 0;
    float EmeraldSplashTmAttack = 450.f;
    //меню









    srand(time(NULL));
    Music music1;
    music1.openFromFile("music1.ogg");
    music1.play();
    music1.setVolume(30);
    music1.setLoop(true);
    Font font;
    font.loadFromFile("SparkyStonesRegular.ttf");



    Music WRtheme;
    WRtheme.openFromFile("sounds\\themes\\WR_Theme.ogg");
    WRtheme.setVolume(10);
    WRtheme.setLoop(true);

    Music SAWtheme;
    SAWtheme.openFromFile("sounds\\themes\\SAW_Theme.ogg");
    SAWtheme.setVolume(10);
    SAWtheme.setLoop(true);


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



    RenderWindow window(sf::VideoMode::getDesktopMode(), "Jojo SFML",
        Style::Titlebar | Style::Close | Style::Fullscreen);
    window.setFramerateLimit(60);






    sf::View view(sf::FloatRect(0.f, 0.f, WINDOW_X, WINDOW_Y));
    view.setCenter(player1.sprite.getPosition()); // устанавливаем центр камеры на игрока
    window.setView(view);
    NPCInit(Haider, "sprites\\npc\\HaiderLoh.png", { 1578 ,360 });

    HudInit(MandomClockHUD, "sprites\\hud\\MandomClock1.png");
    HudInit(InventoryArrow, "sprites\\hud\\ARROW.png");
    HudInit(AngeloHealth, "sprites\\hud\\angeloHealth10.png");

    VragiInit(YopAngelo, "sprites\\npc\\YoAngelo.png", 0, 100.f, { 2377,1064 }, true);

    PowrsObjectsINIT(timestoppower, "sprites\\powers\\TimeStop.png");
    PowrsObjectsINIT(WrOxyImage, "sprites\\powers\\WRoxygen.png");

    StandInit(playerstand, "sprites\\stands\\THE_WORLD_RIGHT.png");
    // RandomObjectsINIT(arrow1, ARROW_FILE_NAME); 
    PlayerInit(player1, PLAYER1RIGHT_FILE_NAME);
    MapObjectsINIT(Map1, "sprites\\map\\MAP.png", { 0,0 });
    MapObjectsINIT(ArrowSand, "sprites\\map\\SANDARROWS.png", { 1567,1654 });
    QuestsInit(quest1, "sprites\\quests\\quest1.png");
    QuestsInit(quest2, "sprites\\quests\\quest2.png");



    AuraInit(plAura, "sprites\\stands\\auras\\TwAuraFrame1.png");



    sf::Image icon;
    icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //  Text HealthAngeloTest(std::to_string(YopAngelo.health), font, 160);
    Text VersionText(VERSION_NAME, font, 50);
    Text ArrowKolInv(std::to_string(ArrowInv), font, 40);
    ArrowKolInv.setFillColor(sf::Color::Black);
    if (testrazrab == true) {
        std::cin >> player1.stand;
    }

    while (window.isOpen()) {

        Vector2i pixelPos = sf::Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        Event event;
        while (MenuOn == true) {
            view.setCenter(960, 540);
            window.setView(view);
            pixelPos = sf::Mouse::getPosition(window);
            pos = window.mapPixelToCoords(pixelPos);
            menu(window, pos);
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            else if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Q && playerstand.visible == false && player1.stand != 0)
            {
                standsummonsound.play();
                if (player1.left == true) {
                    if (player1.stand == 1) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
                    }
                    if (player1.stand == 2) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x + 50, player1.sprite.getPosition().y);
                    }

                    if (player1.stand == 3) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
                    }
                    if (player1.stand == 4) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
                    }
                    if (player1.stand == 5) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x + 60, player1.sprite.getPosition().y - 50);
                    }
                }
                if (player1.left == false) {
                    if (player1.stand == 1) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
                    }


                    if (player1.stand == 2) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x - 20, player1.sprite.getPosition().y);
                    }

                    if (player1.stand == 3) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
                    }
                    if (player1.stand == 4) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
                    }
                    if (player1.stand == 5) {
                        playerstand.sprite.setPosition(player1.sprite.getPosition().x - 60, player1.sprite.getPosition().y - 50);
                    }
                }


                playerstand.visible = true;
            }
            else if (event.type == sf::Event::KeyReleased &&
                event.key.code == sf::Keyboard::Q && playerstand.visible == true && player1.stand != 0)
            {
                playerstand.visible = false;
            }
            else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::E && player1.sprite.getGlobalBounds().intersects(ArrowSand.sprite.getGlobalBounds())) {

                if (rand() % 5 == 1) {
                    ++ArrowInv;
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
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (InventoryArrow.sprite.getGlobalBounds().contains(pos.x, pos.y)) {

                        if (ArrowInv > 0) {
                            player1.stand = rand() % 5 + 1;
                            --ArrowInv;
                        }
                    }

                }
            }

        }
    
        //колиззия

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

        if (player1.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds()) && YopAngelo.health > 0) {
            if (player1.left == true && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player1.sprite.move(PlSpeedX, 0);
            }
            if (player1.left == false && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player1.sprite.move(-PlSpeedX, 0);
            }
            if (player1.up == true && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player1.sprite.move(0, PlSpeedY);
            }
            if (player1.up == false && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player1.sprite.move(0, -PlSpeedY);
            }
        }

        if (playerstand.visible == true) {
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
        }





        if (player1.health <= 0) {
            window.close();
        }

        if (player1.sprite.getGlobalBounds().intersects(ArrowSand.sprite.getGlobalBounds())) {
            ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWSCONTOUR.png");
        }
        else {
            ArrowSand.texture.loadFromFile("sprites\\map\\SANDARROWS.png");
        }
        if (player1.sprite.getGlobalBounds().intersects(Haider.sprite.getGlobalBounds())) {
            if (player1.left == true && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player1.sprite.move(PlSpeedX, 0);
            }
            if (player1.left == false && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player1.sprite.move(-PlSpeedX, 0);
            }
            if (player1.up == true && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player1.sprite.move(0, PlSpeedY);
            }
            if (player1.up == false && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player1.sprite.move(0, -PlSpeedY);
            }
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

        if (player1.stand != 4 || playerstand.visible == false) {
            isEmeraldSplash = false;
            EmeraldSplashsound.stop();
        }

        //квесты

        if (player1.stand > 0) {
            quest1.active = false;
            quest1.done = true;
        }
        if (YopAngelo.health <= 0) {
            quest2.active = false;
            quest2.done = true;
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




        if (MandomTime.getElapsedTime().asSeconds() > 0.f && MandomTime.getElapsedTime().asSeconds() < 1.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock1.png");
        }
        else if (MandomTime.getElapsedTime().asSeconds() > 1.f && MandomTime.getElapsedTime().asSeconds() < 2.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock2.png");
        }
        else if (MandomTime.getElapsedTime().asSeconds() > 2.f && MandomTime.getElapsedTime().asSeconds() < 3.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock3.png");
        }
        else if (MandomTime.getElapsedTime().asSeconds() > 3.f && MandomTime.getElapsedTime().asSeconds() < 4.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock4.png");
        }
        else if (MandomTime.getElapsedTime().asSeconds() > 4.f && MandomTime.getElapsedTime().asSeconds() < 5.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock5.png");
        }
        else if (MandomTime.getElapsedTime().asSeconds() > 5.f && MandomTime.getElapsedTime().asSeconds() < 6.f) {
            MandomClockHUD.texture.loadFromFile("sprites\\hud\\MandomClock6.png");
        }


        if (InventoryArrow.sprite.getGlobalBounds().contains(pos.x, pos.y)) {
            InventoryArrow.texture.loadFromFile("sprites\\hud\\ARROWCONTOUR.png");
        }
        else {
            InventoryArrow.texture.loadFromFile("sprites\\hud\\ARROW.png");
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
        WrOxyDamagePl(WrOxyImage, player1);
        WrOxyDamageVragov(WrOxyImage, YopAngelo);
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

            Laser* laser = new Laser(posCenter, player1);
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

            Bubles* bubles = new Bubles(posCenter, player1);
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

        if (playerstand.barrage == true) {
            if (player1.stand == 1) {
                sf::Vector2f pos = playerstand.sprite.getPosition();
                sf::FloatRect bounds = playerstand.sprite.getGlobalBounds();
                sf::Vector2f posCenter = sf::Vector2f{ 0,	0 };
                if (player1.left == true) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2 - 44,	pos.y + bounds.height / 2 };
                }
                if (player1.left == false) {
                    posCenter = sf::Vector2f{ pos.x + bounds.width / 2,	pos.y + bounds.height / 2 };
                }

                BarrageHands* barragehands = new BarrageHands(posCenter, player1,"sprites\\hud\\MandomClock6.png");
                BarrageHandsSprites.push_back(barragehands);
                
            }
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


        if (playerstand.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds()) && playerstand.barrage == true) {
            if (player1.stand == 1) {
                YopAngelo.health = YopAngelo.health - 0.09;
            }
            if (player1.stand == 3) {
                YopAngelo.health = YopAngelo.health - 0.1;
            }
            if (player1.stand == 4) {
                YopAngelo.health = YopAngelo.health - 0.1;
            }
            if (player1.stand == 5) {
                YopAngelo.health = YopAngelo.health - 0.2;
            }
        }
        PlayerUpdate(player1, PlSpeedX, PlSpeedY, PLAYER1LEFT_FILE_NAME, "sprites\\player\\player1rightmove1.png", "sprites\\player\\player1leftmove1.png", PLAYER1RIGHT_FILE_NAME, playerstand);
        AuraUpdate(plAura, player1, playerstand);
        Powersbjupdate(timestoppower, { player1.sprite.getPosition().x - 370, player1.sprite.getPosition().y - 425 }, 1);
        //RandomObjupdate(window.getSize().x, window.getSize().y, arrow1);
        StandUpdate(playerstand, player1);


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
            window.close();
        }
        ArrowKolInv.setString(std::to_string(ArrowInv));
        if (player1.sprite.getPosition().x + 22 >= 979 && player1.sprite.getPosition().x + 22 <= 2872) {
            view.setCenter(player1.sprite.getPosition().x + 22, view.getCenter().y);
        }
        if (player1.sprite.getPosition().y >= 544 && player1.sprite.getPosition().y <= 1609) {
            view.setCenter(view.getCenter().x, player1.sprite.getPosition().y);
        }
        if (player1.sprite.getPosition().y <= 544 && player1.sprite.getPosition().y >= 1609) {
            view.setCenter(view.getCenter().x, player1.sprite.getPosition().y);
        }

        // HealthAngeloTest.setPosition(view.getCenter().x - 965, view.getCenter().y - 565);
        VersionText.setPosition(view.getCenter().x - 950, view.getCenter().y + 450);
        Questsupdate(quest1, { view.getCenter().x - 970, view.getCenter().y - 370 });
        Questsupdate(quest2, { view.getCenter().x - 970, view.getCenter().y - 370 });
        HUDobjupdate(AngeloHealth, { YopAngelo.sprite.getPosition().x - 35, YopAngelo.sprite.getPosition().y - 40 }, 1);
        HUDobjupdate(InventoryArrow, { view.getCenter().x - 75, view.getCenter().y + 350 }, 1);
        ArrowKolInv.setPosition(InventoryArrow.sprite.getPosition().x + 150, InventoryArrow.sprite.getPosition().y - 30);
        HUDobjupdate(MandomClockHUD, { view.getCenter().x + 800, view.getCenter().y + 350 }, 1);
        for (auto laser : laserSprites) {
            laser->update();
        }
        for (auto bubles : BublesSprites) {
            bubles->update();
        }
        window.setView(view);
        window.clear();

        MapObjectsDraw(window, Map1);
        MapObjectsDraw(window, ArrowSand);
        //RandomObjectsDraw(window, arrow1);
        VragiDraw(window, YopAngelo);
        NPCDraw(window, Haider);
        if (YopAngelo.health > 0) {
            HudDraw(window, AngeloHealth);
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

        PowersObjectsDraw(window, timestoppower);
        PowersObjectsDraw(window, WrOxyImage);
        if (player1.stand == 2) {
            HudDraw(window, MandomClockHUD);
        }
        HudDraw(window, InventoryArrow);


        QuestsDraw(window, quest1);
        QuestsDraw(window, quest2);
        window.draw(VersionText);

        //  window.draw(HealthAngeloTest);
        window.draw(ArrowKolInv);


    
        window.display();
    }
    return 0;
}
