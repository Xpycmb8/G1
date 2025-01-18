{if min_mass 500 ; тяжелый вес и большая скорость
	{if effector "steel"
		{spawn "spheredust_big_hit_steel"}
		{if rand 0.4
			{spawn "wound_steel_big_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_steel_big_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_steel_big_02"  random_orientation}	
		else
			{spawn "wound_steel_big_03"  random_orientation}	
		}
	else effector "armor"
		{spawn "spheredust_big_hit_steel"}
		{if rand 0.4
			{spawn "wound_steel_big_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_steel_big_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_steel_big_02"  random_orientation}	
		else
			{spawn "wound_steel_big_03"  random_orientation}	
		}
	else effector "misc"
		{spawn "spheredust_big_hit_misc"}
		{if rand 0.4
			{spawn "wound_misc_big_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_misc_big_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_misc_big_02"  random_orientation}	
		else
			{spawn "wound_misc_big_03"  random_orientation}	
		}
	else effector "kevlar"
		{spawn "spheredust_big_hit_misc"}
		{if rand 0.4
			{spawn "wound_misc_big_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_misc_big_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_misc_big_02"  random_orientation}	
		else
			{spawn "wound_misc_big_03"  random_orientation}	
		}
	else effector "wood"
		{spawn "spheredust_big_hit_wood"}
		{if rand 0.5
			{spawn "wound_wood_big_00"  random_orientation}	
		else
			{spawn "wound_wood_big_01"  random_orientation}	
		}
	else effector "concrete"
		{spawn "spheredust_big_hit_concrete"}
		{if rand 0.5
			{spawn "wound_wood_big_00"  random_orientation}	
		else
			{spawn "wound_wood_big_01"  random_orientation}	
		}
	}
else min_mass 150 ; малый вес и большая скорость
	{if effector "steel"
		{spawn "spheredust_small_short2"}
		{if rand 0.4
			{spawn "wound_steel_med_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_steel_med_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_steel_med_02"  random_orientation}	
		else
			{spawn "wound_steel_med_03"  random_orientation}	
		}
	else effector "armor"
		{spawn "spheredust_small_short2"}
		{if rand 0.4
			{spawn "wound_steel_med_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_steel_med_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_steel_med_02"  random_orientation}	
		else
			{spawn "wound_steel_med_03"  random_orientation}	
		}
	else effector "misc"
		{spawn "spheredust_small_short2"}
		{if rand 0.4
			{spawn "wound_misc_med_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_misc_med_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_misc_med_02"  random_orientation}	
		else
			{spawn "wound_misc_med_03"  random_orientation}	
		}
	else effector "kevlar"
		{spawn "spheredust_small_short2"}
		{if rand 0.4
			{spawn "wound_misc_med_00"  random_orientation}	
		else rand 0.3
			{spawn "wound_misc_med_01"  random_orientation}	
		else rand 0.2
			{spawn "wound_misc_med_02"  random_orientation}	
		else
			{spawn "wound_misc_med_03"  random_orientation}	
		}
	else effector "wood"
		{spawn "spheredust_small_short2"}
		{if rand 0.5
			{spawn "wound_wood_med_00"  random_orientation}	
		else
			{spawn "wound_wood_med_01"  random_orientation}	
		}
	else effector "concrete"
		{spawn "spheredust_small_short2"}
		{if rand 0.5
			{spawn "wound_wood_med_00"  random_orientation}	
		else
			{spawn "wound_wood_med_01"  random_orientation}	
		}
	}
}

{if effector "ex_molot_fire"
	{spawn "pyro_fire_fuel_puddle" random_orientation}
	{spawn "pyro_fire_fuel_start_ground" random_orientation}
}
{if effector "ex_molot_fire_small"
	{spawn "pyro_fire_fuel_puddle" random_orientation}
	{spawn "pyro_fire_fuel_start_ground" random_orientation}
}
