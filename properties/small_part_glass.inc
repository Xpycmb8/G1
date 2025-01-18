game_entity
	{simulation {able 1} {state 1}}
	{constrain none}
	{obstacleID "construction"}
	{collider "grenade"}
	{props "small" "part" "glass" "misc"}
	{mass 1}
	{skeleton
		{bone "basis"
			{matrix34
				1  0  0
				0 -1  0
				0  0  1
				0  0  0
			}
		}
	}
	{volume "body"
		{able
			{contact 1} {contact_ground 1}
			{bullet 1} {throwing 0} {obstacle 1}
			{overlap 1} {visible 0} {blast 1}
			{touch 0}
		}
		{density 0.007}
	}
	{lodclass "part_small"}
