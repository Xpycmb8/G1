game_entity
	(include "seasons.inc")
	{props "wood" "tree" "normal_light" "wind_has_foliage"}
	(define "armor_wound"
		{armor
			{setting "body"
				{ray_cast_thickness 0}
				{threshold
					{pierce 
						{value 0.1}
					}
				}
				{volumes "bole*"}
			}
		}
	)
	("armor_wound")	
	{volume "base"
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole"}
	}

	(define "base"
		{volume "base%0"
			{able {touch 0} {visible 1}}
			{thickness 20}
			{tags "bole"}
		}
	)
	("base" args 1)
	("base" args 2)
	("base" args 3)
	("base" args 4)
	("base" args 5)
	("base" args 6)
	("base" args 7)
	("base" args 8)
	("base" args 9)
	("base" args 10)
	{volume "bole"
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole"}
	}

	(define "bole"
		{volume "bole%0"
			{able {touch 0} {visible 1}}
			{thickness 20}
			{tags "bole"}
		}
	)

	("bole" args 1)
	("bole" args 2)
	("bole" args 3)
	("bole" args 4)
	("bole" args 5)
	("bole" args 6)
	("bole" args 7)
	("bole" args 8)
	("bole" args 9)
	("bole" args 10)
	("bole" args 11)
	("bole" args 12)
	("bole" args 13)
	("bole" args 14)
	("bole" args 15)
	("bole" args 16)
	("bole" args 17)
	("bole" args 18)
	("bole" args 19)

	{volume "crown"
		{able
			{contact 0} {contact_ground 0}
			{bullet 0} {throwing 0} {obstacle 0}
			{overlap 1} {visible 0}
			{touch 1}
		}
		{density 0.007}
	}
	{simulatorId "pillar"}
	{collider 	"tree"}
	{obstacleID "tree"}
	{mass 500}	
	{volume defaultmaterial "wood"}
;	{ZClipVisibility 1}
	{NoGroupMesh 1}
	{lodclass "decor_tree"}
