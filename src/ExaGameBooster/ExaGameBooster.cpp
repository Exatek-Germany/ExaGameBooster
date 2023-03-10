// ExaGameBooster.cpp
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <cstdio>
#include <tchar.h>
#include <stdint.h>
#include <intrin.h>
#include <map>
#include <strsafe.h>
#include "ExaGameBooster.h"
#include <chrono>
#include <thread>
#include "Util.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;

string games[] = { "speedrunners.exe","love.exe","holodrive.exe","grip-win64-shipping.exe","hellion.exe","eocapp.exe","war-win64-shipping.exe","unturned_be.exe","unturned.exe","battlerite.exe","leagueclientux.exe","league of legends.exe","lol.exe","lolex.exe","tslgame.exe","tslgame_be.exe","csgo.exe","overwatch.exe",">javaw.exe","minecraft.windows.exe","javaw.exe","wow-64.exe","wow.exe","hearthstone.exe","dota2.exe","gta5.exe","rainbowsix.exe","rainbowsix_be.exe","rainbowsixgame.exe","rocketleague.exe","heroes of the storm.exe","heroesofthestorm.exe","heroesofthestorm_x64.exe","hl2.exe",">hl2.exe","h1z1.exe","shootergame.exe","shootergame_be.exe","pathofexilesteam.exe","pathofexile_x64steam.exe","pathofexile_x64.exe","pathofexile.exe","hl2tf.exe","rustclient.exe","rust.exe","worldoftanks.exe","ffxiv.exe","ffxiv_dx11.exe","geometrydash.exe","dolphin.exe","terraria.exe","brawlhalla.exe","walkingdead101.exe","sonicmania.exe","golf with your friends.exe","cities.exe","arma3.exe","left4dead2.exe","project64.exe","jagexlauncher.exe","osbuddy.exe","swiftkit-rs.exe","runescape.exe","osbuddy64.exe","deadbydaylight-win64-shipping.exe","deadbydaylight.exe","aces.exe","worldofwarships.exe","duelyst.exe","bf1.exe","isaac-ng.exe","blackdesert64.exe","blackdesert32.exe","steamlauncher.exe","hiveswap-act1.exe","hoi4.exe","monaco.exe","client.exe","playbns.exe","civilizationv_dx11.exe","smiteeac.exe","smite.exe","factorio.exe","diablo iii.exe","diablo iii64.exe","starcraft ii.exe","sc2.exe","sc2_x64.exe","tesv.exe","skyrimlauncher.exe","tesv_original.exe","thedivision.exe","the division.exe","dontstarve.exe","dontstarve_steam.exe","shellshocklive.exe","spaceengineers.exe","eurotrucks2.exe","portal2.exe","ts4_x64.exe","ts4.exe","blackops3.exe","stardew valley.exe","darksoulsiii.exe","fallout4.exe","falloutnv.exe","maplestory.exe","witcher3.exe","hl2hl2.exe","bf4cte.exe","bf4.exe","xcom2.exe","gw2-64.exe","gw2.exe","skyrimselauncher.exe","skse64_loader.exe","skyrimse.exe","toothandtail.exe","olgame.exe","depthgame.exe","tabletop simulator.exe","stellaris.exe","glyphclientapp.exe","trove.exe","gang beasts.exe","theforest.exe","insurgency.exe","insurgency_be.exe","eu4.exe","townofsalem.exe","robocraftclient.exe","robocraft.exe","golfit-win64-shipping.exe","shadowverse.exe","7daystodie_eac.exe","7daystodie.exe","kfgame.exe","starcraft.exe","undertale.exe","duckgame.exe","shootergame-win32-shipping.exe","businesstour.exe","falloutshelter.exe","slimerancher.exe","lms.exe","titanfall2.exe","starwarsbattlefront.exe","binkplay.exe","mb_warband.exe","swtor.exe","planetside2_x64.exe","planetside2_x86.exe","clicker heroes.exe","psychonauts.exe","amtrucks.exe","codwaw.exe","codwawmp.exe","crossout-d3d9.exe","crossout.exe","dofus.exe","comedy night.exe","etg.exe","elitedangerous64.exe","elitedangerous.exe","elitedangerous32.exe","wizardgraphicalclient.exe","wizard101.exe","adventure-capitalist.exe","empires2.exe","aok hd.exe","age2_x1.exe","exefile.exe","evelauncher.exe","heat_signature.exe","rimworld914win.exe","rimworldwin.exe","rivalsofaether.exe","beamng.drive.exe","beamng.drive.x64.exe","subnautica.exe","civilizationvi.exe","eso.exe","eso64.exe","doomx64.exe","ftlgame.exe","realm of the mad god.exe","justcause3.exe","hl2p.exe","deadcells.exe","fifa17.exe","dbxv2.exe","summercamp.exe","prison architect.exe","tekkengame-win64-shipping.exe","theescapists2.exe","ck2game.exe","microsimulator.exe","shadowofmordor.exe","mgsvmgo.exe","mgsvtpp.exe","idledragons.exe","huniepop.exe","ultimatechickenhorse.exe","nierautomata.exe","darksoulsii.exe","warhammer2.exe","skullgirls.exe","farmingsimulator2017game.exe","100orange.exe","necrodancer.exe","t6zm.exe","t6mp.exe","t6sp.exe","sonic2app.exe","battles-win.exe","dishonored.exe","svencoop.exe","tower-win64-shipping.exe","dyinglightgame.exe","cmw.exe","squad.exe","astro-win64-shipping.exe","creativerse.exe","abewin.exe","grw.exe","vermintide.exe","battleblocktheater.exe","killingfloor.exe","ksp_x64.exe","ksp.exe","rottr.exe","castle.exe","thenewz.exe","tbl-win64-shipping.exe","starwarsbattlefrontii.exe","cuphead.exe","nsuns4.exe","tera.exe","saintsrowiv.exe","absolver-win64-shipping.exe","launcher.exe","scrapmechanic.exe","oxygennotincluded.exe","hl.exe","nuclearthrone.exe","ts3.exe","ts3w.exe","ravenfield.exe","lifeisstrange.exe","hollow_knight.exe","saintsrowthethird_dx11.exe","saintsrowthethird.exe","planetcoaster.exe","dishonored2.exe","clustertruck.exe","crushcrush.exe","bf3.exe","ww2.exe","reliccoh2.exe","realmgrinderdesktop.exe","pcars64.exe","pcars.exe","gh3.exe","robloxplayerbeta.exe","roblox.exe","gta_sa.exe","gta-sa.exe","payday2_win32_release.exe","ballisticoverkill.exe","s2_mp64_ship.exe","s2_sp64_ship.exe","osu!.exe","destiny2.exe","hob.exe","falloutw.exe","shadowofwar.exe","descenders.exe","wolfneworder_x64.exe","dayofinfamy_be.exe","dayofinfamy.exe","deceit.exe","darkest.exe","batim.exe","hatintimegame.exe","besiege.exe","life is strange - before the storm.exe","guns up.exe","h1z1_be.exe","dlpc.exe","fifa18.exe","sanctumgame-win32-shipping.exe","human.exe","watch_dogs.exe","acorigins.exe","cs2d.exe","newcolossus_x64vk.exe","dayz_x64.exe","dayz.exe","brutallegend.exe","zombidle.exe","srhk.exe","vngame.exe","thebureau.exe","elsword.exe","x2.exe","rome2.exe","pizzeria simulator.exe","gettingoverit.exe","gunsoficarusonline.exe","gunsnboxes.exe","vrchat.exe","red crucible.exe","ac4bfsp.exe","ac4bfmp.exe","escapefromtarkov.exe","scpsl.exe","theyarebillions.exe","tld.exe","pokemon trading card game online.exe","kingdom.exe","gwent.exe","long live santa.exe","slaythespire.exe","kingdomsandcastles.exe","northgard.exe","broforce_beta.exe","crossfire.exe","gameclient.exe","neverwinter.exe","tibia.exe","papersplease.exe","cw.exe","sporeapp.exe","plagueincevolved.exe","borderlandspresequel.exe","hotlinemiami.exe","homefront.exe","thehuntercotw_f.exe","tombraider.exe","isaac.exe","binding_of_isaac.exe","we were here.exe","this war of mine.exe","hotlinemiami2.exe","wulverblade.exe","hand simulator.exe","kingdomcome.exe","dbfighterz.exe","battalion.exe","wotblitz.exe","dnf.exe","darksouls.exe ","arena.exe","ddlc.exe","borderlands2.exe","selkis_x64.exe","soulworker.exe","hunt.exe","warframe.exe","warframe.x64.exe","war3.exe","warcraft iii.exe","frozen throne.exe","wc3.exe","bastion.exe","accgame-win32-shipping.exe","assassinscreed_dx10.exe","assassinscreediigame.exe","ac3sp.exe","ac3mp.exe","acc.exe","acu.exe","acbmp.exe","acbsp.exe","acrsp.exe","batmanak.exe","batmanorigins.exe","arkhamvr.exe","bge.exe","fear.exe","fearxp.exe","fear2.exe","f.e.a.r. 3.exe","farcry.exe","farcry2.exe","farcry4.exe","fcprimal.exe","forhonor.exe","injustice.exe","jd2017.exe","legohobbit.exe","lego_worlds_dx11.exe","madmax.exe","mkke.exe","mk10.exe","rayman legends.exe","rayman origins.exe","rocksmith2014.exe","scribble.exe","steep.exe","thecrew.exe","legoemmet.exe","future soldier.exe","future soldier dx11.exe","splintercell.exe","blacklist_dx11_game.exe","trackmaniaturbo.exe","trials_fusion.exe","watchdogs2.exe","darksiderspc.exe","darksiders1.exe","elex.exe","whitesilence-win64-shipping.exe","ic.exe","oride.exe","ori.exe","redfaction.exe","spellforce2.exe","guild3.exe","firewatch.exe","witness64_d3d11.exe","talos.exe","thesurge.exe","rebelgalaxygog.exe","rebelgalaxysteam.exe","fractured space.exe","spacegame-win64-shipping.exe","pa.exe","hyperlightdrifter.exe","stonehearth.exe","obduction-win64-shipping.exe","shovelknight.exe","bc.exe","wolcen.exe","planetnomads.exe","aom_release_final.exe","deadislandgame.exe","deadislandriptidegame.exe","deadislandgame_x86_rwdi.exe","dirt4.exe","f1_2016.exe","f1_2017.exe","metro.exe","metro2033.exe","metroll.exe","micromachines.exe","mn9game.exe","risen.exe","ryse.exe","sr2_pc.exe","bridgeconstructor.exe","bridge_constructor_portal.exe","deadage.exe","seum.exe","bioshock2.exe","bioshock2hd.exe","bioshockinfinite.exe","bioshock.exe","bioshockhd.exe","borderlands.exe","game.exe","mafia2.exe","mafia3.exe","civilizationbe_mantle.exe","civilizationbe_dx11.exe","wwe2k18_x64.exe","deponia.exe","shadow tactics.exe","silence.exe","gonner.exe","dungeoneering.exe","antihero.exe","letthemcome.exe","legoswtfa_dx11.exe","legomarvelavengers_dx11.exe","legomarvelavengers.exe","legojurassicworld_dx11.exe","from_dust.exe","rocksmith.exe","ghostrecon.exe","arcania.exe","mxvsatv.exe","dwarves.exe","sunless skies.exe","lotdgame.exe","sacred3.exe","tane.exe","theinnerworld.exe","acfc.exe","acs.exe","bgt.exe","fc3_blooddragon_d3d11_b.exe","iamalive_game.exe","princeofpersia_launcher.exe","blackmirror.exe","darksiders2.exe","dflw.exe","fsw2.exe","menofvalor.exe","nexus.exe","sinemoraex.exe","sphinxd_gl.exe","bout2.exe","europa1400gold_tl.exe","europa1400gold.exe","udk.exe","shroud of the avatar.exe","descent.exe","escapedeadisland.exe","bridge_constructor_medieval.exe","bridgeconstructorplayground.exe","wmv9codec.exe","bridge_constructor_stunts.exe","deadly30.exe","dubdash.exe","looterkings.exe","pixel heroes - byte and magic.exe","rockfest.exe","slime-san.exe","anb.exe","aer.exe","anna.exe","blackguards.exe","blackguards 2.exe","cm3.exe","harvey.exe","edna.exe","joar.exe","pillars.exe","memoria.exe","munin.exe","shootingstars.exe","satinav.exe","tljh-win64-shipping.exe","rabbit.exe","twwse.exe","kathyrain.exe","uurnog.exe","dandara.exe","armikrog.exe","toren.exe","cojgunslinger.exe","trialsblooddragon.exe","dftfd.exe","locksquest.exe","rad-win64-shipping.exe","tachyon.exe","critterchronicles.exe","inside.exe","the universim.exe","autostarter.exe","grotesque tactics.exe","in between.exe","meridian - new world.exe","safetyfirst.exe","townsmen.exe","vikingrage.exe","windscape.exe","ac3lhd_32.exe","justice_league_vr_the_complete_experience-1.0.1-htcvive-release.exe","justice_league_vr_the_complete_experience-1.0.0-htcvive-release.exe","south park - the stick of truth.exe","battleworldskronos.exe","ocd.exe","joshua.exe","police.exe","superhot.exe","sh.exe","losthorizon2.exe","fsasgame.exe","cloudsandsheep2.exe","futurewars.exe","gameroyale2.exe","greed.exe","holyavatarvs.exe","squad22.exe","raceabit.exe","shiny.exe","skilltree.exe","soulcraft.exe","stellarimpact.exe","submerge-win64-shipping.exe","super treasure arena.exe","trappeddeadlockdown.exe","tristoy.exe","trulon.exe","twinsector_steam.exe","engine.exe","homm3 2.0.exe","h5_game.exe","legobatman2.exe","legobatman.exe","legoharrypotter.exe","sh3.exe","southpark_tfbw.exe","witn.exe","ravenshield.exe","r6vegas_game.exe","r6vegas2_game.exe","splintercell3.exe","guildii.exe","soma.exe","hellbladegame-win64-shipping.exe","drt.exe","kidgame.exe","saintsrowgatoutofhell.exe","the banner saga.exe","tmforever.exe","trialsfmx.exe","rivergame-win64-shipping.exe","dreamfall chapters.exe","risen3.exe","sacred2.exe","deponia2.exe","the banner saga 2.exe","tormentorxpunisher.exe","tormentorxpunishergit.exe","shippingpc-bmgame.exe","bia.exe","cojbibgame_x86.exe","childoflight.exe","princeofpersia.exe","sh5.exe","sh4.exe","dfbhd.exe","painkiller.exe","spellforce.exe","cure.exe","dungeondefenders.exe","dundefgame.exe","cof.exe","blackwake.exe","age3.exe","age3y.exe","farcry3_d3d11.exe","farcry3.exe","fm.exe","attila.exe","ffxv_s.exe","evolve.exe","shogun2.exe","breach.exe","reactivedrop.exe","left4dead.exe","amnesia.exe","nw.exe","application-steam-x64.exe","ogat.exe","whosyourdaddy.exe","iw4mp.exe","iw4sp.exe","torchlight2.exe","supermeatboy.exe","mowas2.exe","mowas_2.exe","darwin-win64-shipping.exe","darwin.exe","hyperuniverse.exe","grim dawn.exe","rogame.exe","fishingplanet.exe","assettocorsa.exe","acshowroom.exe","aim hero.exe","sfm.exe","polybridge.exe","dirt3_game.exe","goatgame-win32-shipping.exe","risk of rain.exe","bombtag.exe","miscreated.exe","thehunter.exe","cortex command.exe","mgv.exe","blocknload.exe","lethalleague.exe","sniperelite4.exe","endlessspace2.exe","deadmaze.exe","wowt-64.exe","sniperelite3_mantle.exe","magicka.exe","streetfighterv.exe","streetfightervbeta-win64-shipping.exe","dead space.exe","superflight.exe","witcher2.exe","spintires.exe","bloodandbacon.exe","cms2018.exe","ddda.exe","projectzomboid64.exe","projectzomboid32.exe","hero_siege.exe","postal2.exe","playsnow.exe","poolians.exe","btd5-win.exe","dxmd.exe","ktane.exe","aomx.exe","f1_2015.exe","overcooked.exe","witcher.exe","pickcrafter.exe","nfs13.exe","speed.exe","one finger death punch.exe","the elder scrolls legends.exe","pitpeople.exe","magicduels.exe","swkotor2.exe","client_tos.exe","toribash.exe","jediacademy.exe","jamp.exe","jasp.exe","fsd-win64-shipping.exe","stranded_deep_x64.exe","eco.exe","hideandshriek-win64-shipping.exe","apb.exe","blackopsmp.exe","blackops.exe","prey.exe","metroconflict.exe","spelunky.exe","medieval2.exe","magicka2.exe","uno.exe","nioh.exe","relicdow3.exe","fortniteclient-win64-shipping.exe","unleash.exe","insulam-win64-shipping.exe","archeage.exe","wakfu.exe","fsx.exe","mitosis.exe","genitaljousting.exe","universe sandbox x64.exe","_launcher.exe","farcry5.exe","darknessii.exe","starwarsg.exe","sweaw.exe","main.exe","mindnight.exe","zps.exe","playjcmp.exe","simcity.exe","frostpunk.exe","hurtworld.exe","hurtworldclient.exe","moderncombatversus.exe","quantumbreak.exe","the jackbox party pack 3.exe","appdata.exe","radicalheights.exe","mysummercar.exe","specopstheline.exe","f13.exe","1914-1918 series.exe","verdun.exe","disasm.exe","nms.exe","ylands.exe","re7.exe","battletech.exe","superhexagon.exe","pixark.exe","satellitereignwindows.exe","pillarsofeternity.exe","conansandbox_be.exe","conansandbox.exe","maniaplanet.exe","nfs16.exe","dungeonoftheendless.exe","endlesslegend.exe","deep space waifu.exe","marssteam.exe","dragonageinquisition.exe","masseffectandromeda.exe","ttrengine.exe","survarium.exe","gw2.main_win64_retail.exe","armoredwarfare.exe","expendabros.exe","mountyourfriends.exe","pcars2avx.exe","shakes and fidget.exe","sas4-win.exe","awesomenauts.exe","rpg_rt.exe","holdfast naw.exe","learn to fly 3.exe","stories.exe","layers of fear.exe","star trek online.exe","minionmasters.exe","soulstorm.exe","uebs.exe","terratechwin32.exe","airmech.exe","mudrunner.exe","swarm.exe","hacknet.exe","quakechampions.exe","ironsnout.exe","darksoulsremastered.exe","darksouls.exe","raft.exe","dungreed.exe","gtaiv.exe","synergy.exe","wizardoflegend.exe","kritika_client.exe","mirrorsedge.exe","cms2015.exe","swkotor.exe","stanley.exe","tyranny.exe","empyrion.exe","bless.exe","60seconds.exe","theescapists.exe","dauntless-win64-shipping.exe","daorigins.exe","thrones.exe","okami.exe","adventure-communist.exe","gop3.exe","wormsrevolution.exe","lanoire.exe","morrowind.exe","armello.exe","nba2k18.exe","mwoclient.exe","mechwarrioronline.exe","re5dx9.exe","houseflipper.exe","sdhdship.exe","ff7_en.exe","hwr.exe","youtuberslife.exe","bio4.exe","stateofdecay.exe","argobattleye.exe","eseaclient.exe","eseaclientsteam.exe","zat.exe","iw5sp.exe","iw5mp.exe","yetanotherzombiedefense.exe","cpucores.exe","wargame3.exe","bh6.exe","castleminerz.exe","lotroclient.exe","ftk.exe","justcause2.exe","rxgame-win64-shipping.exe","dow2.exe","paintthetownred.exe","bms.exe","vindictus.exe","batmanac.exe","night in the woods.exe","doorkickers.exe","warmode.exe","sniperghostwarrior2.exe","bfbc2game.exe","limbo.exe","helldivers.exe","teeworlds.exe","moonbasealphagame.exe","mcengine.exe","lss.exe","swrepubliccommando.exe","thelab.exe","citra-qt.exe","saofb-win64-shipping.exe","bit heroes.exe","orcsmustdie2.exe","dcgame.exe","bootggxrd.exe","guiltygearxrd.exe","battleroyaletrainer-win64-shipping.exe","patriots.exe","the jackbox party pack 2.exe","aion.bin","ai.exe","sins of a solar empire rebellion.exe","dbxv.exe","supremecommander.exe","spellsworn-win64-test.exe","masseffect3.exe","superhotvr.exe","blackdesertpatcher32.pae.exe","gta-vc.exe","gta--vc.exe","dmlauncher.exe","mirrorsedgecatalyst.exe","anno5.exe","cm_client.exe","faeria.exe","everlasting summer.exe","dnl.exe","steeldivision.exe","aamfp.exe","rwby-ge.exe","dmc-devilmaycry.exe","supremecommander2.exe","dxhrdc.exe","dxhr.exe","freestyle2.exe","furi.exe","ssfiv.exe","rift.exe","rift_x64.exe","oneshot.exe","highoctanedrift.exe","ruiner-win64-shipping.exe","pso2.exe","swordwithsauce-win64-shipping.exe","masseffect.exe","turmoil_pc_full.exe","wa.exe","pillarsofeternityii.exe","pcbs.exe","streetsofrogue.exe","hma.exe","maxpayne3.exe","xr_3da.exe","recroom_release.exe","portia.exe","lost_castle.exe","dungeon.exe","fallout3.exe","rwr_game.exe","emily is away.exe","tactical monsters.exe","payday_win32_release.exe","brickrigs-win64-shipping.exe","aq3d.exe","bayonetta.exe","boringmangame.exe","me2game.exe","masseffect2.exe","shadowwarrior2.exe","empire.exe","burnoutparadise.exe","sh-win64-shipping.exe","arma2oa_be.exe","mulegend.exe","houseparty.exe","relichunterszero.exe","eqclient.exe","eqgame.exe","wildstar64.exe","wildstar.exe","spooky.exe","stalker-cop.exe","xrengine.exe","forts.exe","hon.exe","osirisnewdawn.exe","sw.x64.exe","aagame.exe","crusader2.exe","owlboy.exe","reigns.exe","zula_launcher.exe","tales of berseria.exe","shootyskies.exe","huniecamstudio.exe","bombercrew.exe","lsgame_be.exe","sf2.exe","dfufg.exe","dfubg.exe","minimetro.exe","dinohordegame.exe","trickytowers.exe","ss2013.exe","the jackbox party pack 4.exe","contagion.exe","simpleplanes.exe","rpgmv.exe","fez.exe","fivenightsatfreddys.exe","injustice2.exe","eternal.exe","drift racing online.exe","tew2.exe","prog.exe","mb_wfas.exe","secretworldlegends.exe","secretworldlegendsdx11.exe","victoria2.exe","call_to_arms.exe","legostarwarssaga.exe","justfishing.exe","domina.exe","quakelive_steam.exe","quakelive.exe","spitfiredashboard.exe","loadout.exe","farmingsimulator2015game.exe","rometw.exe","fallout4vr.exe","magicite.exe","bully.exe","nidhogg.exe","blacksurvival.exe","fortify.exe","avorion.exe","sam3.exe","goldrushthegame.exe","nino2.exe","roa2-win64-shipping.exe","skyforge.exe","meteor60seconds.exe","yugioh.exe","beat saber.exe","sf3clientfinal.exe","tq.exe","segagameroom.exe","execpubg.exe","overgrowth.exe","ddadds.exe","reckoning.exe","starcitizen.exe","nfs11.exe","bfh.exe","worldofwarplanes.exe","railworks.exe","frontend.exe","ball 3d.exe","passpartout.exe","monsterprom.exe","totallyaccuratebattlegrounds.exe","avgame-win64-shipping.exe","outlast2.exe","portal_knights_x64.exe","fenris-win64-shipping.exe","toxikk.exe","iracingsim64.exe","iracingsim.exe","celeste.exe","audiosurf.exe","baldur.exe","civ3conquests.exe","warhammer_x64_11.exe","littlenightmares.exe","rct.exe","xgamefinal.exe","jwe.exe","defiance.exe","shipping-thiefgame.exe","from_the_depths.exe","asamu-win32-shipping.exe","moonlighter.exe","pirate101.exe","pirate.exe","dreadgame-win64-shipping.exe","napoleon.exe","ava.exe","arpiel.exe","heroes.exe","l2.exe","lineageii.exe","maplestory2.exe","ppssppwindows.exe","ppssppwindows64.exe","generals.exe","nox.exe","tribesascend.exe","medievalengineers.exe","enlisted.exe","propwitchhuntmodule-win64-shipping.exe","grid2.exe","grid2_avx.exe","nomad.exe","gorn.exe","unreal.exe","shadowrun.exe","spacehulkgame-win64-shipping.exe","colonyclient.exe","murder miners.exe","ge2rb.exe","aimtastic.exe","iw7_ship.exe","transistor.exe","legomarvel.exe","salt.exe","transportfever.exe","edf41.exe","thecrew2.exe","titan.exe","metal gear rising revengeance.exe","nextday_game.exe","disco dodgeball.exe","yo_cm_client.exe","bloodbowl2_dx_32.exe","pokernight2.exe","fivenightsatfreddys2.exe","captainspirit-win64-shipping.exe","freeman guerrilla warfare.exe","hammerwatch.exe","rct3plus.exe","jalopy.exe","ultimate custom night.exe","fable anniversary.exe","pavlov-win64-shipping.exe","styx2-win64-shipping.exe","audiosurf2.exe","slap city.exe","ns2.exe","to the moon.exe","devilmaycry4_dx10.exe","devimaycry4.exe","devilmaycry4_dx9.exe","devilmaycry4specialedition.exe","evilwithin.exe","lordsofthefallen.exe","sisterlocation.exe","legoninjago_dx11.exe","tjpp.exe","nekopara_vol1.exe","gta3.exe","worldsadrift.exe","we were here too.exe","farmtogether.exe","vampire.exe","stoneshard.exe","csd2.exe","darkcrusade.exe","ffx.exe","hmm.exe","sos-win64-shipping.exe","wreckfest_x64.exe","cardhunter.exe","traktor.amalgam.app.exe","amorous.game.windows.exe","pixelworlds.exe","starbound.exe","starbound_opengl.exe","lawbreakers.exe","h3vr.exe","rct2.exe","openrct2.exe","crashbandicootnsanetrilogy.exe","ionbranch.exe","ionbranch_be.exe","ros.exe","aow3.exe","rf4_x64.exe","omensight.exe","sundered.exe","crookz.exe","sshock.exe","system shock.exe","metronomicon.exe","dungeons2.exe","tropico4.exe","rfg.exe","hellbound-win64-shipping.exe","madmachines.exe","mgsgroundzeroes.exe","bloody trapland.exe","wormis.exe","cossacks.exe","gw.exe","sims2ep9.exe","project_rhombus.exe","climb.exe","ra3.exe","ra3ep1.exe","clone drone in the danger zone.exe","police2.exe","darksiders3.exe","deadrising3.exe","dinodday.exe","the banner saga 3.exe","warrobots.exe","mobiusff.exe","democracy3.exe","celebritypoker.exe","momodorarutm.exe","arizonasunshine.exe","deblob.exe","deblob2.exe","kenshi_x64.exe","140.exe","rrre64.exe","stronghold crusader.exe","sgw3.exe","mm.exe","beholder.exe","bbtag.exe","w40k.exe","feed and grow.exe","punch club.exe","halfdead.exe","worms w.m.d.exe","pyre.exe","monsterhunterworld.exe","among us.exe","viridi.exe","offworld.exe","west of loathing.exe","dosbox.exe","lastyear-win64-shippinggame.exe","rampage_knights.exe","yakuza0.exe","otherlandsclient-win64-shipping.exe","overcooked2.exe","fallout2.exe","fallout2hr.exe","theexit-win64-shipping.exe","rage.exe","orwell.exe","timeclickers.exe","prominence-win64-shipping.exe","getwrecked.exe","paintball war.exe","postscriptum.exe","crawl.exe","danganronpa.exe","911.exe","howtosurvive2.exe","deadrising2.exe","graveyard keeper.exe","showerdad.exe","valkyria.exe","hotlava.exe","simcity 4.exe","brokeprotocol.exe","weneedtogodeeper.exe","roguelands.exe","scum.exe","call of war.exe","wesnoth.exe","lisa.exe","spacemarine.exe","insurgencyclient-win64-shipping.exe","onward.exe","tph.exe","talisman.exe","gunpoint.exe","iw3sp.exe","iw3mp.exe","deadfrontier2.exe","throneoflies.exe","badnorth.exe","hungerdungeon.exe","the dig.exe","deusex.exe","gc2twilightofthearnor.exe","stickfight.exe","civilization4.exe","xcomgame.exe","xcomew.exe","nba2k17.exe","neptuniarebirth1.exe","szoneonline.exe","rerev2.exe","trine1_32bit.exe","trine.exe","trine3_64bit.exe","trine3_32bit.exe","trine2_32bit.exe","jobsimulator.exe","fifa16.exe","consim2015.exe","wl2.exe","ss2.exe","system shock2.exe","shock2.exe","sottr.exe","onraid.exe","blackops4.exe","chess.exe","chaosrebornwin64.exe","brokenage.exe","steamrun.exe","discipl2.exe","disciple.exe","flatout2.exe","fouc.exe","se4.exe","masters of anima.exe","ponyisland.exe","vvvvvv.exe","theendisnigh.exe","towerfall.exe","dragon quest xi.exe","regularhumanbasketball.exe","f1_2018.exe","never split the party.exe","thewolfamongus.exe","brothers.exe","abzugame-win64-shipping.exe","lastdayofjune.exe","cities in motion.exe","darkest houren.exe","darkest hour.exe","darkest hourkr.exe","eu3game.exe","eu3.exe","hoi3game.exe","hoi3_tfh_kor.exe","hoi3_tfh.exe","hoi3.exe","majestyhd.exe","dragonfall.exe","torchlight.exe","stranger.exe","casino.exe","battlegrounds_cc.exe","battlegrounds.exe","swgbg.exe","battlegrounds_x2.exe","battlegrounds_x1.exe","swgbwide_x1.exe","walkingdead4.exe","jediknight.exe","jedi.exe","jk.exe","yookalaylee64.exe","misec.exe","mise.exe","jk2sp.exe","jk2mp.exe","jk2mvmp_x64.exe","jk2mvmp_x86.exe","ascension.exe","ascensiongame.exe","ashesescalation_dx11.exe","ticket to ride.exe","killer queen black.exe","killerqueenx.exe","nnt.exe","ootp18.exe","tropico3.exe","hoi2.exe","europa_client.exe","victoria.exe","indiana jones and the fate of atlantis.exe","monkey2.exe","eurotrucks.exe","galciv3.exe","victory.exe","rpgvxace.exe","wildeight.exe","planetbase.exe","avp_dx11.exe","avp3.exe","bbcf.exe","foxgame-win32-shipping.exe","20xx.exe","legion td 2.exe","coloringpixels.exe","u1game.exe","battleriteroyale.exe","roguelegacy.exe","mistsurv-win64-shipping.exe","rememberinghowwemet.exe","advhd.exe","studyinsteampunk.exe","actionhenk.exe","aeon rivals.exe","ageofconan.exe","ageofconandx10.exe","aiwar.exe","alan_wakes_american_nightmare.exe","albion-online.exe","alienbreed2assault.exe","altitude.exe","anarchy.exe","anarchyonline.exe","anno4.exe","anno2205.exe","thespacegame.exe","cactus.exe","astebreed.exe","axiomverge.exe","rats.exe","baremetal.exe","battlesquares.exe","bf2.exe","bf2142.exe","beathazard.exe","bejeweled3.exe","bejblitz.exe","heroblocks.exe","blocksport.exe","blockland.exe","bloodlinechampions.exe","boid.exe","braid.exe","shippingpc-stormgame.exe","c9.exe","cabal.exe","cabalmain.exe","cod2sp_s.exe","cod2mp_s.exe","coj.exe","coj_dx10.exe","cargocommander.exe","chronicon.exe","realliveen.exe","undying.exe","clonk.exe","cloudbuilt.exe","combatarms.exe","cnc3ep1.exe","reliccoh.exe","csdsteambuild.exe","csdgogbuild.exe","creationkit.exe","creationkit32.exe","cw3.exe","crimsonland.exe","crowfallclient.exe","cryptark.exe","crysis64.exe","crysis.exe","crysis2.exe","crysis3.exe","cyphers.exe","darkstarone.exe","dcs.exe","deadspace2.exe","deadcore.exe","default.exe","debugger.exe","defensegrid2_release.exe","depressionquest.exe","dd.exe","devilian.exe","diablo.exe","diablo ii.exe","diadraempty.exe","diadraempty154lw.exe","diadraempty154plus.exe","distance.exe","dominions4.exe","doom3.exe","doom.exe","doubledragon.exe","downwell.exe","dragonage2.exe","dragonfinsoup.exe","dragonnest.exe","ddo.exe","dropzonesteamclient_x32_rel.exe","juggernautclient_x32_rel.exe","dukeforever.exe","dfo.exe","dungeonland.exe","dndclient.exe","dndclient64.exe","dustaet.exe","dustforce.exe","entropia.exe","everquest2.exe","evoland2.exe","fairyfencer.exe","fifa15.exe","ff3_win32.exe","ffv_game.exe","ff6.exe","ff8_fr.exe","ff8_es.exe","ff8_en.exe","ffxiiiimg.exe","ffxiii2img.exe","ffxiii2.exe","firefallclient.exe","flamebreak.exe","neuz.exe","forza_x64_release_final.exe","forzamotorsport7.exe","fran bow.exe","ftp.exe","fp.exe","frontier.exe","client.jar","furcadia.exe","geargame.exe","ge.exe","caggame-win64-shipping.exe","caggameserver.exe","goog.exe","scram.exe","gcst.exe","growhome.exe","client_x86.exe","ggxxacpr_win.exe","ghwt.exe","haloce.exe","halo.exe","hand of fate.exe","hardwest.exe","hate plus.exe","hatoful.exe","hawkengame-win32-shipping.exe","hawkengame-win64-shipping.exe","hex.exe","hitmanbloodmoney.exe","hoshimemo.exe","ibbobb.exe","indeath-win64-shipping.exe","intruder.exe","jadeempire.exe","jurassicpark100.exe","kindredspirits.exe","kag.exe","krosmaster arena.exe","krosmaster.exe","launchpad.exe","landmark64.exe","lcgol.exe","legendofdungeon.exe","lrff13.exe","lro.exe","lineage.exe","loco.exe","longlivethequeen.exe","lovelyplanet.exe","loversinadangerousspacetime.exe","lumini_win64.exe","lyne.exe","mro-win64-shipping.exe","marvelheroes2015.exe","marvelheroesomega.exe","marvelheroes2016.exe","massive.exe","masterreboot.exe","nekojishi.exe","howtosurvive.exe","kingmaker.exe","nekopara_vol0.exe","necropolis.exe","acodyssey.exe","craftworld.exe","midair-win64-test.exe","crosscode-beta.exe","jotun.exe","monster slayers db.exe","glimpsegame.exe","lostsaga.exe","mow_assault_squad_ed.exe","mow_assault_squad.exe","mow_assualt_squad.exe","might & magic heroes vi.exe","mmh7game-win64-shipping.exe","towerofguns2-win64-shipping.exe","mountain.exe","mudlet.exe","mugensouls.exe","ns3fb.exe","nsuns3.exe","nsunsr.exe","nfsc.exe","neoscavenger.exe","neocronclient.exe","wreckfest.exe","nicole.exe","nosgoth.exe","oppw3.exe","oni.exe","popcapgame1.exe","peggle.exe","peggleextreme.exe","pinaball arcade.exe","pinballarcade.exe","pd.exe","pixel_dungeons.exe","shooterultimate.exe","mwlllauncher.exe","plantsvszombies.exe","poi.exe","pokemmo.exe","pokerstars.exe","prepar3d.exe","primalcarnagegame.exe","pw_game.exe","rik.exe","proteus.exe","pyrite heart.exe","quake2.exe","quiplash.exe","racethesun.exe","ragexe.exe","clragexe.exe","sframe.exe","rayman2.exe","revolt.exe","rvgl.exe","reassemblyrelease.exe","recore.exe","rerev.exe","hidden folks.exe","talesofescape.exe","blockpost.exe","moonhunters.exe","sam2.exe","bhd.exe","thewalkingdead2.exe","pla_toon-win64-shipping.exe","darkwood.exe","nba2k19.exe","iambread.exe","bigscreen.exe","fuse.exe","sonicgenerations.exe","zeus-win64-shipping.exe","themisfits.exe","ww3-win64-shipping.exe","soulcaliburvi.exe","ohsir.exe","dr2_us.exe","otwd-win64-shipping.exe","callofcthulhu.exe","acclient.exe","reflex.exe","retrocityrampage.exe","reus.exe","tianyu.exe","rfactor.exe","rfactor2.exe","roguesystemsim.exe","sakura angels.exe","sakura clicker.exe","sakura spirit.exe","screencheat.exe","scrivener.exe","secretponchosd3d11.exe","secrets of grindea.exe","shadowgrounds.exe","survivor.exe","shantae and the pirate's curse.exe","shantaecurse.exe","shatteredskies.exe","railroads.exe","sinarun.exe","slime ccg.exe","los-win64-shipping.exe","snes9x.exe","songbringer.exe","sonic adventure dx.exe","slw.exe","soulaxiom.exe","spazgame.exe","spacechem.exe","sprintvector-win64-shipping.exe","startupcompany.exe","seagame.exe","steinsgate.exe","steredenn.exe","strafe.exe","strife.exe","strife-ve.exe","styxgame.exe","suguri.exe","supermncgameclient.exe","swordandsworcery_pc.exe","survive-win64-shipping.exe","swat4x.exe","swat4.exe","swordcoast.exe","sword of asumi.exe","synthetik.exe","tkom.exe","t-engine.exe","monkeyisland104.exe","monkeyisland101.exe","monkeyisland102.exe","monkeyisland105.exe","monkeyisland103.exe","tales of zestiria.exe","trgame.exe","taskforce.exe","tetrisultimate.exe","tetris.exe","beginnersguide.exe","oblivion.exe","forgettabledungeon.exe","kingoffighters2002um.exe","misstake.exe","thepark.exe","the sacred tears true.exe","thesecretworlddx11.exe","thesecretworld.exe","settlers7r.exe","settlers6.exe","astronautsgame-win64-shipping.exe","ethancarter-win64-shipping.exe","therewasacaveman.exe","thomaswasalone.exe","tis100.exe","tomb2.exe","tomb3.exe","tra.exe","pctomb5.exe","trl.exe","tomb4.exe","tru.exe","thug.exe","thug2.exe","trackday manager.exe","transforbest.exe","tripletown.exe","unravel.exe","unrealtournament.exe","ut3.exe","uplink.exe","wftogame.exe","warsow_x86.exe","warsow_x64.exe","waveland.exe","wings of vi.exe","wolfoldblood_x64.exe","wolfoldblood_x86.exe","wolfoldblood_x32.exe","wonder wickets.exe","wonderwickets-release.exe","x-plane.exe","xenonauts.exe","zandronum.exe","zombi.exe","marsgame.exe","rfstl.exe","fxgame.exe","alanwake.exe","argentum.exe","gv_win.exe","allegiance.exe","shodn.exe","aseprite.exe","brawler2d.exe","?????????????????????????????????.exe","avalonlords.exe","blackshot.exe","bbcse.exe","blobby.exe","boundless.exe","cabal2main.exe","cataclysm-tiles.exe","chaoscode.exe","chronicle.exe","cm black sea.exe","cm shock force.exe","gamemd.exe","command.exe","cosmic.exe","cosmicbreak2.exe","cosmicleague.exe","creeper world 2.exe","carrier.exe","demul.exe","desertsofkharak32.exe","desertsofkharak64.exe","dis1_st.exe","disneyinfinity3.exe","disneyinfinity2.exe","dqxgame.exe","eye.exe","ezquake-gl.exe","ezquake.exe","fable.exe","thmhj.exe","fceux.exe","pol.exe","gahkthun.exe","garfield_master7.exe","garfieldkartnomulti.exe","skydrift.exe","grandia2.exe","gridautosport_avx.exe","grisaia.exe","gpt_vol2.exe","heavyweapon.exe","neptuniarebirth2.exe","neptuniarebirth3.exe","java.exe","openitg-pc.exe","invisibleinc.exe","ivac.exe","justcause.exe","age.exe","kara no shojo 2.exe","kopp2.exe","mtga.exe","mban_m.exe","mban_f.exe","maschine 2.exe","mbaa.exe","mgs2_sse.exe","modlands.exe","neoaquarium.exe","offspring fling.exe","olliolli2.exe","organtrail.exe","projectg.exe","perpetuum.exe","psobb.exe","pbbg_win32.exe","hedra.exe","icons.exe","brggame-steam.exe","dirt2_game.exe","nxsteam.exe","mabinogi.exe","mgsi.exe","mapleroyals.exe","hindie.steam.exe","hindie.exe","infantry.exe","tds.exe","helbreath.exe","r3air.exe","ffr.exe","dwarf fortress.exe","quake3.exe","kofxiii.exe","nitronicrush.exe","pcsx2-r5875.exe","pcsx2.exe","phase_shift.exe","torment.exe","qubegame.exe","reboundarena.exe","regen.exe","retroarch.exe","wolfsp.exe","wolfmp.exe","darkfall_roa.exe","darkfall.exe","rks.exe","rks_e.exe","s4client.exe","sc2vn.exe","shadowcomplex-win32.exe","shadowcomplex-win32-egl.exe","asn_app_pcdx9_final.exe","epsxe.exe","soulworker100.exe","spyparty.exe","ssfexe.exe","ssf2.exe","tfil.exe","tlr.exe","simpsons.exe","thrillville07.exe","titanfall.exe","tmnt2.exe","traod_p4.exe","th10.exe","th10e.exe","th105e.exe","th105.exe","th11e.exe","th11.exe","th12.exe","th12e.exe","th123e.exe","th123.exe","th125e.exe","th125.exe","th128.exe","th128e.exe","th13.exe","th13e.exe","th135e.exe","th135.exe","th14e.exe","th14.exe","th143e.exe","th143.exe","th145.exe","th145e.exe","th15e.exe","th15.exe","th155.exe","th07.exe","th07e.exe","th075.exe","th075e.exe","th08e.exe","th08.exe","th09.exe","th09e.exe","th095e.exe","th095.exe","gn_enbu.exe","tsa.exe","ed6_win.exe","ed6_win_dx9.exe","ed6_win2_dx9.exe","ed6_win2.exe","va-11 hall a.exe","visualboyadvance.exe","warzone2100.exe","wz2100.exe","xonotic.exe","ygopro_vs.exe","zsnesw.exe","zwiftapp.exe","aogame.exe","murderouspursuits.exe","sao_hr.exe","aimlab_tb.exe","parkasaurus.exe","visage-win64-shipping.exe","kynseed.exe","thronebreaker.exe","fallout76.exe","bfv.exe","battlechefbrigade.exe","kingsway.exe","zenzizenzic.exe","Borderlands3.exe","realm.exe","realmeac.exe","ashen-win64-shipping.exe","hades.exe","farcrynewdawn.exe","atlasgame_be.exe","paladinseac.exe","paladins.exe","sotgame.exe","harry2.exe","subnauticazero.exe","grb.exe","grb_upp.exe","grb_vulkan.exe","r5apex.exe","farmingsimulator2019game.exe","vermintide2.exe","anthem.exe","spellbreak.exe","heroesandgeneralsdesktop.exe","hng.exe","dawnofman.exe","thedivision2.exe","temtem.exe","zoneue4-win64-shipping.exe","bloodstainedrotn-win64-shipping.exe","sekiro.exe","risk of rain 2.exe","factorygame-win64-shipping.exe","mordhau-win64-shipping.exe","baba is you.exe","staxel.modmanager.exe","staxel.steamlauncher.exe","staxel.client.exe","supremerulerultimate.exe","underlords.exe","pubglite.exe","pubglite-win64-shipping.exe","pubg lite.exe","launcher_updater.exe","gurrah-win64-shipping.exe","gurrah.exe","llblaze.exe","bloonstd6.exe","btdadventuretime.exe","wowclassic.exe","tower keepers.exe","gears5.exe","control_dx11.exe","control_dx12.exe","modernwarfare.exe","lor.exe","indianaepicgamestore-win64-shipping.exe","rdr2.exe","starwarsjedifallenorder.exe","potbs.exe","mcc-win64-shipping.exe","forzahorizon4.exe","doometernalx64vk.exe","obradinn.exe","valorant-win64-shipping.exe","aoede_s.exe","aoe2de_s.exe","wurmlauncher64.exe","thesurge2.exe","ds.exe","roguecompany.exe","maine-win64-shipping.exe","fallguys_client.exe","flightsimulator.exe","spellcraft-live.exe","tap.exe","spellcraft-gamelab.exe","spellcraft-staging.exe","genshinimpact.exe","haloinfinite.exe","acvalhalla.exe","il-2.exe","blackopscoldwar.exe","cyberpunk2077.exe","battlefront.exe","battlefrontii.exe","outriders-win64-shipping.exe","tom-win64-shipping.exe","disco.exe","newworldlauncher.exe","newworld.exe","forzahorizon5.exe","lostark.exe","eldenring.exe","cod.exe","sp22-cod.exe","monsterhunterrise.exe","prometheus.exe","prometheus-win64-shipping.exe","mhrisesunbreakdemo.exe","snap.exe","goose goose duck.exe","hogwartslegacy.exe","sonsoftheforest.exe","Bannerlord.exe","Bannerlord.Native.exe","FarCry6.exe","FactoryGame.exe","FarmingSimulator2022.exe","FIFA23.exe","F1_22.exe","F1Manager22.exe","GoW.exe","HITMAN3.exe","hlvr.exe","hops.exe","minecraft.exe","Minecraft.exe","Prison Architect64.exe","ReadyOrNot.exe","Skyrim.exe","SwGame-Win64-Shipping.exe","TheAscent.exe","TransportFever2.exe","TS2Prototype-Win64-Shipping.exe","Universe Sandbox VR.exe","Warhammer3.exe","X4.exe","SpiderManRemastered.exe","WatchDogsLegion.exe","A Plague Tale Requiem.exe","riftbreaker_win_release.exe","HorizonZeroDawn.exe","ACC.exe" };
string allCoreNoVCacheGames[] = { "GTA5.exe", "HITMAN3.exe" };
string cacheGames[] = { "cod.exe", "Cyberpunk2077.exe", "factorio.exe", "FactoryGame.exe", "FarCry6.exe", "ffxiv.exe", "F1_22.exe", "GTA5.exe", "HITMAN3.exe", "hogwartslegacy.exe", "Skyrim.exe", "skyrimse.exe", "VALORANT-Win64-Shipping.exe", "Warhammer3.exe", "RDR2.exe", "sottr.exe", "Wow.exe", "SpiderManRemastered.exe", "WatchDogsLegion.exe", "A Plague Tale Requiem.exe", "riftbreaker_win_release.exe", "HorizonZeroDawn.exe", "ACC.exe","escapefromtarkov.exe"};
string services[] = {"BsgLauncher.exe", "chrome.exe", "Discord.exe", "ExaGameBooster.exe", "firefox.exe", "lghub.exe", "L-Connect 3.exe", "msedge.exe", "nextcloud.exe","obs64.exe", "SamsungMagician.exe", "ShareX.exe", "Spotify.exe", "steamwebhelper.exe", "ts3client_win64.exe", "wallpaper64.exe"};

// AMD Ryzen (5950X, 7950X, 7950X3D P-Die)
DWORD_PTR ccd0mask = 65535; // Core0 - Core7 (with SMT)
DWORD_PTR ccd1mask = 4294901760;  // Core8 - Core15 (with SMT)

// AMD Ryzen (7950X3D Cache-Die)
DWORD_PTR vcachemask = ccd0mask;  // Core0 - Core7 (witch V-Cache, with SMT)

// AMD Ryzen (5900X, 7900X, 7900X3D P-Die)
DWORD_PTR ccd0mask12c = 4095; // Core0 - Core7 (with SMT)
DWORD_PTR ccd1mask12c = 16773120; // Core8 - Core15 (with SMT)

// AMD Ryzen (7900X3D Cache-Die)
DWORD_PTR vcachemask12c = ccd0mask12c;  // Core0 - Core5 (with V-Cache, with SMT)

//Intel Alder-Lake/Raptor-Lake (P-Cores)
DWORD_PTR intel4pcoremask = 255; // Core0 - Core3 (with HT)
DWORD_PTR intel6pcoremask = 4095; // Core0 - Core5 (with HT)
DWORD_PTR intel8pcoremask = 65535; // Core0 - Core7 (with HT)

//Intel Alder-Lake/Raptor-Lake (E-Cores)
DWORD_PTR intel6p4ecoremask = 61440; // (8+4) 12600 + 13400
DWORD_PTR intel6p8ecoremask = 1044480; // (6+8) 13600 + 13500
DWORD_PTR intel8p4ecoremask = 983040; // (8+4) 12700
DWORD_PTR intel8p8ecoremask = 16711680; // (8+8) 12900 + 13700
DWORD_PTR intel8p16ecoremask = 4294901760; // (8+16) 13900

bool vcacheInUse = false;
string cpuBrandStringCache = "";

string getCpuBrandString()
{
    if ("" != cpuBrandStringCache)
    {
        return cpuBrandStringCache;
    }

    int CPUInfo[4] = { -1 };
    unsigned   nExIds, i = 0;
    char CPUBrandString[0x40];

    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);

    nExIds = CPUInfo[0];
    for (i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(CPUInfo, i);

        // Interpret CPU brand string
        if (i == 0x80000002)
        {
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        }
        else if (i == 0x80000003)
        {
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        }
        else if (i == 0x80000004)
        {
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
        }
    }

    cout << "CPU Type: " << CPUBrandString << endl;

    cpuBrandStringCache = string(CPUBrandString);

    return string(CPUBrandString);
}

DWORD_PTR getGameProcessAffinityMask(string game)
{
    string CPUBrandString = getCpuBrandString();

    // intel is ez, just take p-cores
    // mobile
    if (CPUBrandString.find("13980HX") != string::npos || CPUBrandString.find("13950HX") != string::npos || CPUBrandString.find("13900HX") != string::npos || CPUBrandString.find("13850HX") != string::npos || CPUBrandString.find("13700HX") != string::npos || CPUBrandString.find("12950HX") != string::npos || CPUBrandString.find("12900HX") != string::npos || CPUBrandString.find("12850HX") != string::npos || CPUBrandString.find("12800HX") != string::npos)
    {
        cout << "found! apply intel8pcoremask" << endl;
        return intel8pcoremask;
    }
    else if (CPUBrandString.find("13900HK") != string::npos || CPUBrandString.find("13905H") != string::npos || CPUBrandString.find("13900H") != string::npos || CPUBrandString.find("13800H") != string::npos || CPUBrandString.find("13705H") != string::npos || CPUBrandString.find("13700H") != string::npos || CPUBrandString.find("13620H") != string::npos || CPUBrandString.find("13650HX") != string::npos || CPUBrandString.find("13600HX") != string::npos || CPUBrandString.find("13500HX") != string::npos || CPUBrandString.find("13450HX") != string::npos || CPUBrandString.find("12900HK") != string::npos || CPUBrandString.find("12900H") != string::npos || CPUBrandString.find("12800H") != string::npos || CPUBrandString.find("12700H") != string::npos || CPUBrandString.find("12650H") != string::npos || CPUBrandString.find("1370P") != string::npos || CPUBrandString.find("1280P") != string::npos)
    {
        cout << "found! apply intel6pcoremask" << endl;
        return intel6pcoremask;
    }
    else if (CPUBrandString.find("13600H") != string::npos || CPUBrandString.find("13505H") != string::npos || CPUBrandString.find("13500H") != string::npos || CPUBrandString.find("3420H") != string::npos || CPUBrandString.find("12600H") != string::npos || CPUBrandString.find("12500H") != string::npos || CPUBrandString.find("12450H") != string::npos || CPUBrandString.find("1360P") != string::npos || CPUBrandString.find("1350P") != string::npos || CPUBrandString.find("1340P") != string::npos || CPUBrandString.find("1270P") != string::npos || CPUBrandString.find("1260P") != string::npos || CPUBrandString.find("1250P") != string::npos || CPUBrandString.find("1240P") != string::npos)
    {
        cout << "found! apply intel4pcoremask" << endl;
        return intel4pcoremask;
    }
    // desktop
    else if (CPUBrandString.find("13900") != string::npos || CPUBrandString.find("12900") != string::npos || CPUBrandString.find("13700") != string::npos || CPUBrandString.find("12700") != string::npos)
    {
        cout << "found! apply intel8pcoremask" << endl;
        return intel8pcoremask;
    }
    else if (CPUBrandString.find("13600") != string::npos || CPUBrandString.find("13500") != string::npos || CPUBrandString.find("13400") != string::npos || CPUBrandString.find("12600K") != string::npos)
    {
        cout << "found! apply intel6pcoremask" << endl;
        return intel6pcoremask;
    }
    else if (CPUBrandString.find("Intel") != string::npos)
    {
        // trust the scheduler :P
        return 0;
    }

    if (CPUBrandString.find("7950X3D") != string::npos)
    {
        for (string cacheGame : cacheGames) {
            // todo: check if compare needs to be lowercased
            if (isEqualTo(cacheGame, game))
            {
                cout << "found! apply vcachemask" << endl;
                vcacheInUse = true;
                return vcachemask;
            }
        }

        cout << "found! apply ccd0mask" << endl;
        return ccd1mask;
    }
    else if (CPUBrandString.find("7900X3D") != string::npos)
    {
        for (string cacheGame : cacheGames) {
            // todo: check if compare needs to be lowercased
            if (isEqualTo(cacheGame, game))
            {
                cout << "found! apply vcachemask12c" << endl;
                vcacheInUse = true;
                return vcachemask12c;
            }
        }

        cout << "found! apply ccd0mask12c" << endl;
        return ccd1mask12c;
    }

    // only apply vache masks => return to stay all core for other CPUs
    for (string allCoreGame : allCoreNoVCacheGames) {
        if (isEqualTo(allCoreGame, game))
        {
            return 0;
        }
    }

    if (CPUBrandString.find("7950X") != string::npos || CPUBrandString.find("5950X") != string::npos || CPUBrandString.find("3950X") != string::npos)
    {
        cout << "found! apply ccd0mask" << endl;
        return ccd0mask;
    }
    else if (CPUBrandString.find("7900") != string::npos || CPUBrandString.find("5900") != string::npos || CPUBrandString.find("3900") != string::npos)
    {
        cout << "found! apply ccd0mask12c" << endl;
        return ccd0mask12c;
    }

    // dont handle other AMD SKUs (no latency penalty issues)
    return 0;
}

DWORD_PTR getServiceProcessAffinityMask(string service)
{
    string CPUBrandString = getCpuBrandString();

    if (CPUBrandString.find("7950X3D") != string::npos)
    {
        cout << "found! apply ccd0mask" << endl;
        if (vcacheInUse)
        {
            return ccd1mask;
        }
        return ccd0mask;
    }
    else if (CPUBrandString.find("7950X") != string::npos || CPUBrandString.find("5950X") != string::npos || CPUBrandString.find("3950X") != string::npos)
    {
        cout << "found! apply ccd1mask" << endl;
        return ccd1mask;
    }
    else if (CPUBrandString.find("7900X3D") != string::npos)
    {
        cout << "found! apply ccd0mask12c" << endl;
        if (vcacheInUse)
        {
            return ccd1mask12c;
        }
        return ccd0mask12c;
    }
    else if (CPUBrandString.find("7900") != string::npos || CPUBrandString.find("5900") != string::npos || CPUBrandString.find("3900") != string::npos)
    {
        cout << "found! apply ccd1mask12c" << endl;
        return ccd1mask12c;
    }

    // intel e-core shitshow
    if (CPUBrandString.find("13900") != string::npos)
    {
        cout << "found! apply intel8p16ecoremask" << endl;
        return intel8p16ecoremask;
    }
    else if (CPUBrandString.find("12900") != string::npos || CPUBrandString.find("13700") != string::npos)
    {
        cout << "found! apply intel8p8ecoremask" << endl;
        return intel8p8ecoremask;
    }
    else if (CPUBrandString.find("12700") != string::npos)
    {
        cout << "found! apply intel8p4ecoremask" << endl;
        return intel8p4ecoremask;
    }
    else if (CPUBrandString.find("13600") != string::npos || CPUBrandString.find("13500") != string::npos)
    {
        cout << "found! apply intel6p8ecoremask" << endl;
        return intel6p8ecoremask;
    }
    else if (CPUBrandString.find("12600K") != string::npos || CPUBrandString.find("13400") != string::npos)
    {
        cout << "found! apply intel6p4ecoremask" << endl;
        return intel6p4ecoremask;
    }
    else if (CPUBrandString.find("Intel") != string::npos)
    {
        // trust the scheduler :P
        return 0;
    }

    return 0;
}

int main()
{
    //freopen("output.log", "w", stdout);
    //freopen("error.log", "w", stderr);

    bool checkRunning = false;

    while (true)
    {
        if (checkRunning)
        {
            chrono::milliseconds timespan(5000);
            this_thread::sleep_for(timespan);

            continue;
        }

        checkRunning = true;
        vcacheInUse = false;
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(PROCESSENTRY32);

        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

        if (Process32First(snapshot, &entry) == TRUE)
        {
            while (Process32Next(snapshot, &entry) == TRUE)
            {
                for (string game : games) {
                    if (_wcsicmp(entry.szExeFile, wstring(game.begin(), game.end()).c_str()) == 0)
                    {
                        cout << "found! " << game << endl;
                        DWORD_PTR mask = getGameProcessAffinityMask(wchar2string(entry.szExeFile));

                        if (0 != mask)
                        {
                            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

                            BOOL success = SetProcessAffinityMask(hProcess, mask);

                            CloseHandle(hProcess);
                        }
                    }
                }
            }
        }

        CloseHandle(snapshot);

        snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

        if (Process32First(snapshot, &entry) == TRUE)
        {
            while (Process32Next(snapshot, &entry) == TRUE)
            {
                for (string service : services) {
                    if (_wcsicmp(entry.szExeFile, wstring(service.begin(), service.end()).c_str()) == 0)
                    {
                        cout << "found! " << service << endl;
                        DWORD_PTR mask = getServiceProcessAffinityMask(wchar2string(entry.szExeFile));

                        if (0 != mask)
                        {
                            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

                            BOOL success = SetProcessAffinityMask(hProcess, mask);

                            CloseHandle(hProcess);
                        }
                    }
                }
            }
        }

        CloseHandle(snapshot);

        chrono::milliseconds timespan(5000);
        this_thread::sleep_for(timespan);

        checkRunning = false;
    }
}
