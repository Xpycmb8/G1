game_entity
	{constrain ground}
	{collider "bush"}
	{obstacleID "nothing"}
	{volume defaultmaterial "wood"}
	{lodclass "decor_small"}
	{volume "crown"
		{thickness 0.5}
		{Able {contact 1} {bullet 1} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}
	}
	{volume "crown_big"
		{thickness 0.5}
		{Able {contact 1} {bullet 1} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}
	}
	{NoGroupMesh 1}