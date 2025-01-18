game_entity
	(include "seasons.inc")
	{props "wood" "tree" "normal_light" "crushed_tree" "ambient_big"}
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
	{volume "bole_main"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main"}
	}
	{volume "bole_main1"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main1"}
	}
	{volume "bole_main2"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main2"}
	}
	{volume "bole_main3"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main3"}
	}
	{volume "bole_main4"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main4"}
	}
	{volume "bole_main5"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 25}
		{tags "bole_main5"}
	}
	{volume "bole_main6"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 20}
		{tags "bole_main6"}
	}
	{volume "bole_upper"
		{material "wood"}		
		{able {touch 0} {visible 1}}
		{thickness 20}
		{tags "bole_crushed_upper"}
	}

	(define "bole"
		{volume "bole%0"
			{able {touch 0} {visible 1}}
			{thickness 20}
			{tags "bole_crushed"}
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
	(define "crown"
		{volume "crown%0"
			{able
				{contact 0} {contact_ground 1}
				{bullet 0} {throwing 0} {obstacle 0}
				{overlap 1} {visible 0}
				{touch 1}
			}
			{density 0.007}
			{tags "crown_crushed"}
		}
	)

	("crown" args 1)
	("crown" args 2)
	("crown" args 3)
	("crown" args 4)
	("crown" args 5)
	("crown" args 6)
	("crown" args 7)
	("crown" args 8)
	("crown" args 9)
	("crown" args 10)
	("crown" args 11)
	("crown" args 12)
	("crown" args 13)
	("crown" args 14)
	("crown" args 15)
	("crown" args 16)
	("crown" args 17)
	("crown" args 18)
	("crown" args 19)
	{simulatorId "pillar"}
	{collider 	"tree"}
	{obstacleID "tree"}
	{mass 900}	
	{volume defaultmaterial "wood"}
;	{ZClipVisibility 1}
	{NoGroupMesh 1}
	{lodclass "decor_tree"}
