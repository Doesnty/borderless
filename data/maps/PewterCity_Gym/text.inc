PewterCity_Gym_Text_BrockIntro:: @ 8190CD4
    .string "So, you're here. I'm Brock.\n"
    .string "I'm Pewter's Gym Leader.\p"
    .string "My rock-hard willpower is evident\n"
    .string "even in my Puppets.\p"
    .string "My Puppets are all rock hard, and\n"
    .string "have true-grit determination.\p"
    .string "That's right - my Puppets are all\n"
    .string "the Earth type!\p"
    .string "Fuhaha! You're going to challenge\n"
    .string "me knowing that you'll lose?\p"
    .string "That's the Trainer's honor that\n"
    .string "compels you to challenge me.\p"
    .string "Fine, then!\n"
    .string "Show me your best!{PLAY_BGM}{MUS_ENCOUNTER_GYM_LEADER}$"

@ NOTE: This defeat text actually causes a buffer overflow. It's too long for the gDisplayedStringBattle
@ buffer that it's put into, and it stomps all over the gBattleTextBuffs after, as well as the otherwise
@ unused array after that, gUnknown_2022AE8. Perhaps that's the reason why said array exists.
PewterCity_Gym_Text_BrockDefeat:: @ 8190E4F
    .string "I took you for granted, and so\n"
    .string "I lost.\p"
    .string "As proof of your victory, I confer\n"
    .string "on you this…the official Puppet\l"
    .string "League BoulderBadge.$"
	
@ not anymore!
    .string "{SIZE}Á{PLAYER} received the BOULDERBADGE\n"
    .string "from BROCK!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
    .string "{SIZE}ÇJust having the BOULDERBADGE makes\n"
    .string "your POKéMON more powerful.\p"
    .string "It also enables the use of the\n"
    .string "move FLASH outside of battle.\p"
    .string "Of course, a POKéMON must know the\n"
    .string "move FLASH to use it.$"

PewterCity_Gym_Text_TakeThisWithYou:: @ 8190FC1
    .string "Wait!\n"
    .string "Take this with you.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock:: @ 8190FDB
    .string "{PLAYER} received TM39\n"
    .string "from Brock.$"

PewterCity_Gym_Text_ExplainTM39:: @ 8190FF8
    .string "A TM, Technical Machine, contains a\n"
    .string "technique for Puppets.\p"
    .string "Using a TM teaches the move it\n"
    .string "contains to a Puppet.\p"
    .string "A TM is good for unlimited uses.\p"
    .string "So, feel free to experiment with\n"
    .string "different strategies using them.\p"
    .string "Anyways…\n"
    .string "TM39 contains Rock Tomb.\p"
    .string "It hurls boulders at the foe and\n"
    .string "lowers its Speed.$"

PewterCity_Gym_Text_BrockPostBattle:: @ 819110F
    .string "There are all kinds of Trainers in\n"
    .string "this huge world of ours.\p"
    .string "You appear to be very gifted as a\n"
    .string "Puppet Trainer.\p"
    .string "So let me make a suggestion.\p"
    .string "Go to the Gym in Cerulean and test\n"
    .string "your abilities.$"

PewterCity_Gym_Text_DontHaveRoomForThis:: @ 81911CE
    .string "You don't have room for this.$"

PewterCity_Gym_Text_LiamIntro:: @ 81911EC
    .string "Stop right there, kid!\p"
    .string "You're ten thousand light-years \n"
    .string "from facing Brock!$"

PewterCity_Gym_Text_LiamDefeat:: @ 8191237
    .string "Darn!\p"
    .string "Light-years isn't time…\n"
    .string "It measures distance!$"

PewterCity_Gym_Text_LiamPostBattle:: @ 819126B
    .string "You're pretty hot.\n"
    .string "…But not as hot as Brock!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop:: @ 8191298
    .string "Hiya!\n"
    .string "Do you want to dream big?\p"
    .string "Do you dare to dream of becoming\n"
    .string "the Puppetry champ?\p"
    .string "I'm no Trainer, but I can advise\n"
    .string "you on how to win.\p"
    .string "Let me take you to the top!$"

PewterCity_Gym_Text_LetsGetHappening:: @ 819133C
    .string "All right!\n"
    .string "Let's get happening!$"

PewterCity_Gym_Text_TryDifferentPartyOrders:: @ 819135C
    .string "Brock uses Earth-type Puppets\n"
    .string "and Earth-type attacks.\p"
    .string "Wind-type Puppets are immune to\n"
    .string "Earth moves, even the ones that\l"
	.string "are rocks falling and such\p"
    .string "If you've got a Nature or Wind\n"
    .string "Puppet, this shouldn't be hard.\p"
	.string "Do pay attention during the fight\n"
	.string "though! His Puppets have some\l"
	.string "unique Abilities to take note of.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening:: @ 8191412
    .string "It's a free service!\n"
    .string "Let's get happening!$"

PewterCity_Gym_Text_YoureChampMaterial:: @ 819143C
    .string "Just as I thought!\n"
    .string "You're Puppetry champ material!$"

PewterCity_Gym_Text_GymStatue:: @ 819146E
    .string "PEWTER PUPPETRY GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "{OTHER_PC}, {RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon:: @ 81914A4
    .string "PEWTER PUPPETRY GYM\n"
    .string "LEADER: BROCK\p"
    .string "WINNING TRAINERS:\n"
    .string "{OTHER_PC}, {RIVAL}, {PLAYER}$"

