game_entity
	(include "construction_generic.inc")
	{props "dummy" "construction" "wire_fall" "no_destroyed_stamp" "parts"}
	{simulatorId "pillar"}
	{ZClipVisibility 0}
	{obstacleID "post"}
	{collider "tree"}
	{mass 200}

	{volume "wire1"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	{volume "wire2"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	{volume "wire3"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	{volume "wire4"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	{volume "wire5"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	{volume "wire6"
		{tags "body" "fire"}
		{thickness 20}
		{able {visible 0} {obstacle 0}}
	}
	
	{lodclass "decor_medium"}