const u8 gMoveNames[][15] = {
    _("-$$$$$$"),
    _("Pound"),
    _("Karate Chop"),
    _("Feint"),
    _("Comet Punch"),
    _("Mega Punch"),
    _("Pay Day"),
    _("Fire Punch"),
    _("Ice Punch"),
    _("Thunder Punch"),
    _("Scratch"),
    _("Night Slash"),
    _("Judgment"),
    _("Razor Wind"),
    _("Swords Dance"),
    _("Cut"),
    _("Gust"),
    _("Wing Attack"),
    _("Whirlwind"),
    _("Fly"),
    _("Bind"),
    _("Braver"),
    _("Vine Whip"),
    _("Stomp"),
    _("Double Kick"),
    _("Mega Kick"),
    _("Jump Kick"),
    _("Rolling Kick"),
    _("Sand Attack"),
    _("Headbutt"),
    _("Knife Throw"),
    _("Magic Knife"),
    _("Sculpture"),
    _("Tackle"),
    _("Body Slam"),
    _("Wrap"),
    _("Take Down"),
    _("Thrash"),
    _("Double-Edge"),
    _("Tail Whip"),
    _("Poison Sting"),
    _("Seal Needle"),
    _("Pin Missile"),
    _("Leer"),
    _("Bite"),
    _("Growl"),
    _("Roar"),
    _("Sing"),
    _("Jamming"),
    _("Sonicboom"),
    _("Disable"),
    _("Poison Tears"),
    _("Ember"),
    _("Flamethrower"),
    _("Mist"),
    _("Water Gun"),
    _("Hydro Pump"),
    _("Surf"),
    _("Ice Beam"),
    _("Blizzard"),
    _("Psybeam"),
    _("Bubblebeam"),
    _("Aurora Beam"),
    _("Hyper Beam"),
    _("Peck"),
    _("Foul Play"),
    _("Submission"),
    _("Skanda's Leg"),
    _("Counter"),
    _("Seismic Toss"),
    _("Strength"),
    _("Absorb"),
    _("Mega Drain"),
    _("Leech Seed"),
    _("Growth"),
    _("Razor Leaf"),
    _("Solarbeam"),
    _("Poison Powder"),
    _("Stun Spore"),
    _("Sleep Powder"),
    _("Petal Storm"),
    _("Mesmerism"),
    _("Dark Pulse"),
    _("Fire Spin"),
    _("Thundershock"),
    _("Thunderbolt"),
    _("Thunder Wave"),
    _("Thunder"),
    _("Rock Wrecker"),
    _("Earthquake"),
    _("Fissure"),
    _("Dig"),
    _("Toxic"),
    _("Psyshot"),
    _("Mana Burst"),
    _("Hypnosis"),
    _("Zen Headbutt"),
    _("Agility"),
    _("Quick Attack"),
    _("Rage"),
    _("Teleport"),
    _("Night Shade"),
    _("Mimic"),
    _("Screech"),
    _("Double Team"),
    _("Recover"),
    _("Harden"),
    _("Minimize"),
    _("Smokescreen"),
    _("Confuse Ray"),
    _("Withdraw"),
    _("Defense Curl"),
    _("Barrier"),
    _("Light Screen"),
    _("Haze"),
    _("Reflect"),
    _("Focus Energy"),
    _("Work Up"),
    _("Metronome"),
    _("Debt Spiral"),
    _("SelfDestruct"),
    _("Mind Bomb"),
    _("Lick"),
    _("Smog"),
    _("Gunk Shot"),
    _("Wood Hammer"),
    _("Fire Blast"),
    _("Waterfall"),
    _("Mana Shield"),
    _("Swift"),
    _("Skull Bash"),
    _("Danmaku"),
    _("Topsy-Turvy"),
    _("Amnesia"),
    _("Luna Dial"),
    _("Soft-Boiled"),
    _("Hi Jump Kick"),
    _("Daunt"),
    _("Dream Eater"),
    _("Ominous Wind"),
    _("Barrage"),
    _("Leech Life"),
    _("Lovely Kiss"),
    _("Sky Attack"),
    _("Transform"),
    _("Bubble"),
    _("Dizzy Punch"),
    _("Burn Powder"),
    _("Flash"),
    _("Psywave"),
    _("Splash"),
    _("Disperse"),
    _("Aqua Jet"),
    _("Explosion"),
    _("Fury Swipes"),
    _("Sucker Punch"),
    _("Rest"),
    _("Rock Slide"),
    _("Killing Bite"),
    _("Sharpen"),
    _("Conversion"),
    _("Tri Attack"),
    _("Giga Impact"),
    _("Slash"),
    _("Substitute"),
    _("Struggle"),
    _("Sketch"),
    _("Shadow Sneak"),
    _("Thief"),
    _("Spider Web"),
    _("Heart's Eye"),
    _("Nightmare"),
    _("Flame Wheel"),
    _("Snore"),
    _("Curse"),
    _("Flail"),
    _("Conversion2"),
    _("Aeroblast"),
    _("Cotton Spore"),
    _("Reversal"),
    _("Spite"),
    _("Powder Snow"),
    _("Protect"),
    _("Mach Punch"),
    _("Scary Face"),
    _("Feint Attack"),
    _("Sweet Kiss"),
    _("Belly Drum"),
    _("Poison Bomb"),
    _("Mud Slap"),
    _("Black Ripple"),
    _("Spikes"),
    _("Discharge"),
    _("Foresight"),
    _("Destiny Bond"),
    _("Perish Song"),
    _("Icy Wind"),
    _("Detect"),
    _("Head Rush"),
    _("Lock-On"),
    _("Outrage"),
    _("Sandstorm"),
    _("Giga Drain"),
    _("Endure"),
    _("Smile"),
    _("Tremors"),
    _("False Swipe"),
    _("Swagger"),
    _("Hospitality"),
    _("Spark"),
    _("Fury Cutter"),
    _("Steel Wing"),
    _("Lure of Death"),
    _("Attract"),
    _("Sleep Talk"),
    _("Heal Bell"),
    _("Final Gambit"),
    _("Prank"),
    _("Frustration"),
    _("Safeguard"),
    _("Pain Split"),
    _("Sacred Fire"),
    _("Magnitude"),
    _("Dynamic Punch"),
    _("Brave Bird"),
    _("Lava Plume"),
    _("Baton Pass"),
    _("Encore"),
    _("Pursuit"),
    _("Rapid Spin"),
    _("Nature Power"),
    _("Steel Fist"),
    _("Metal Claw"),
    _("Vital Throw"),
    _("Energy Light"),
    _("Synthesis"),
    _("LUNATIC"),
    _("Hidden Power"),
    _("Cross Chop"),
    _("Shock Spin"),
    _("Rain Dance"),
    _("Sunny Day"),
    _("Crunch"),
    _("Mirror Coat"),
    _("Psych Up"),
    _("ExtremeSpeed"),
    _("AncientPower"),
    _("Shadow Ball"),
    _("Psycho Cut"),
    _("Rock Smash"),
    _("Whirlpool"),
    _("Drawn Line"),
    _("Fake Out"),
    _("Performance"),
    _("Nasty Plot"),
    _("Mirror Shot"),
    _("Aqua Ring"),
    _("Heat Wave"),
    _("Hail"),
    _("Torment"),
    _("Lucky Chant"),
    _("Will-o-Wisp"),
    _("Memento"),
    _("Facade"),
    _("Focus Punch"),
    _("SmellingSalt"),
    _("Copycat"),
    _("Rock Bullet"),
    _("Charge"),
    _("Taunt"),
    _("Helping Hand"),
    _("Trick"),
    _("Recollection"),
    _("Wish"),
    _("Assist"),
    _("Ingrain"),
    _("Superpower"),
    _("Magic Coat"),
    _("Recycle"),
    _("Revenge"),
    _("Brick Break"),
    _("Yawn"),
    _("Knock Off"),
    _("Endeavor"),
    _("Eruption"),
    _("Skill Swap"),
    _("Imprison"),
    _("Refresh"),
    _("Shadow Dance"),
    _("Snatch"),
    _("Secret Power"),
    _("Shadow Force"),
    _("Force Palm"),
    _("Camouflage"),
    _("Mana Charge"),
    _("Luster Purge"),
    _("Mist Ball"),
    _("Roost"),
    _("Teeter Dance"),
    _("Blaze Kick"),
    _("Earth Power"),
    _("Ice Ball"),
    _("Needle Arm"),
    _("Slack Off"),
    _("Hyper Voice"),
    _("Cross Poison"),
    _("Crush Claw"),
    _("Flare Blitz"),
    _("Dam Breakage"),
    _("Meteor Mash"),
    _("Astonish"),
    _("Weather Ball"),
    _("Aromatherapy"),
    _("Fake Tears"),
    _("Air Slash"),
    _("Overheat"),
    _("Shadow Hit"),
    _("Rock Tomb"),
    _("Silver Wind"),
    _("BindingVoice"),
    _("Nature Sound"),
    _("Tickle"),
    _("Draco Meteor"),
    _("Aqua Shower"),
    _("Signal Beam"),
    _("Shadow Punch"),
    _("Extrasensory"),
    _("Soar"),
    _("Sand Tomb"),
    _("Cold Snap"),
    _("Muddy Water"),
    _("Bullet Seed"),
    _("Blade Flash"),
    _("Ice Shard"),
    _("Iron Defense"),
    _("Block"),
    _("Howl"),
    _("Heat Claw"),
    _("Leaf Storm"),
    _("Bulk Up"),
    _("Bounce"),
    _("Mud Shot"),
    _("Poison Jab"),
    _("Covet"),
    _("Volt Tackle"),
    _("Magical Leaf"),
    _("Splashback"),
    _("Calm Mind"),
    _("Leaf Blade"),
    _("Gale Dance"),
    _("Rock Blast"),
    _("Shock Wave"),
    _("Water Pulse"),
    _("Apollon"),
    _("Psycho Boost"),
    _("Drain Punch"),
    _("Aura Sphere"),
    _("Focus Blast"),
    _("Heart Break"),
    _("Decision"),
    _("Rapid Fire"),
    _("Head Smash"),
    _("Seed Bomb"),
    _("Freeze-Dry"),
    _("Hone Claws"),
    _("Quiver Dance"),
    _("Shell Smash"),
    _("Close Combat"),
    _("Dark Void"),
    _("Trick Room"),
    _("Tailwind"),
    _("U-Turn"),
    _("Volt Switch"),
    _("Purify"),
    _("Horsepower"),
    _("Healing Wish"),
    _("Gale"),
    _("Abyss Nova"),
    _("Mishaguji"),
    _("Aegis Merge"),
    _("Exterminate"),
    _("Oblivion Wing"),
    _("Fire Fang"),
    _("Ice Fang"),
    _("Thunder Fang"),
    _("Acupressure"),
    _("Wild Hunt"),
    _("Manashock"),
    _("Flame Charge"),
    _("Charge Beam"),
    _("Psycho Shift"),
    _("Bestow"),
    _("Hex"),
    _("Power Whip"),
    _("Hammer Arm"),
    _("Bolt Strike"),
    _("Anchor Shot"),
    _("Sutra"),
    _("Pristine Shot"),
    _("Destitution"),
    _("Earth Press"),
    _("Happy Hour"),
    _("Hold Hands"),
    _("Ball Lightning"),
    _("Mood Swing"),
    _("Alpha Strike"),
    _("Lunar Sea"),
    _("Apotheosis"),
    _("Identify"),
    _("Corpse Blaze"),
    _("Group Prank"),
    _("Scald"),
    _("Circle Throw"),
    _("Clear Smog"),
    _("Butchery"),
    _("Beddy Bye"),
    _("Snap Trap"),
	_("Punishment"),
	_("Shriek"),
	_("Flight"),
	_("Core Surge"),
	_("Cataclysm"),
    _("Me First"),
};
