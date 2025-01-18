game_entity
;	(include "seasons.inc")
	{lodclass "decor_bush"}
 	{NoGroupMesh 1}
;	{NoCastShadows}
	{skeleton         
		{bone "basis"}
	}
	{Volume "body"
		{Sphere 8}
		{able
			{window}
			{contact 0} {contact_ground 0}
			{bullet 0} {throwing 0} {obstacle 0}
			{overlap 1} {visible 1}
			{touch 0}
		}
		{density 0}
		{Bone "basis"}
		{material "wood"}
	}
	{collider "bush"}
	{obstacleID "nothing"}
	{props "bush_tiny" "wind_has_foliage"}
	{volume defaultmaterial "wood"}
