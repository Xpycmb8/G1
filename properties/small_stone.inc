{collider "construction"}
{obstacleID "cliff"}
{props "small" "concrete" "cornered" "parts" "construction" "no_destroyed_stamp"}	
{mass 100}

{Volume "rock"
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}
{Volume "body1"
	{tags "body"}
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}
{Volume "body"
	{tags "body"}
	{thickness 50}
	{able {visible 1}{obstacle 0}}
}	
{armor
	{setting "body"
		{threshold {pierce {calibre 12}}}
		{ray_cast_thickness}
		{volumes "body*"}
		{threshold  
			{blast {value 10}}
		}
	}
}

{lodclass "decor_small"}