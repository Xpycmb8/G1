

{"grenade throwing"
	{on ground_hit sync
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{if rand 0.9
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				}
			else min_speed %3
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/med/"}	
				}
			else min_speed %4
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		grass 			30 14 6 )
		("terrain_fx" args "grass" 			grass 			30 14 6 )
		("terrain_fx" args "road" 			concrete 		30 14 6 )
		("terrain_fx" args "country_road" 	concrete 		30 14 6 )
		("terrain_fx" args "sand" 			sand 			30 14 6 )
		("terrain_fx" args "snow"  			mud 			30 14 6 )
		("terrain_fx" args "water" 			water 			30 14 6 )
		("terrain_fx" args "bridge" 		wood			30 14 6 )
		("terrain_fx" args "bridge_wood" 	wood			30 14 6 )
		("terrain_fx" args "floor" 			carpet 			30 14 6 )
		("terrain_fx" args "rock" 			ground 			30 14 6 )
		("terrain_fx" args "metal" 			metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_mtl" 	 metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_mtl_int"  metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_ext" 	 concrete 		30 14 6 )
		("terrain_fx" args "shoot_emit_int"  	concrete 		30 14 6 )
	}
}


{"shortsmg"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{tags add %0}
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/ar/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/ar/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"assaultrifle"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/ar/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/ar/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"mgun"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"	
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/lmg/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/lmg/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"pistol"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/pistol/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/pistol/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"smg"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"				
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/smg/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/smg/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"rocketlauncher"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"			
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/launcher/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.5 
			{spawn "spheredust_small_short2" }
		else rand 0.2 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/launcher/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}
{"shotgun"
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{if rand 0.3 
									{spawn "spheredust_small_short2" }
								else rand 0.1 
									{spawn "spheredust_small_short" }
								}
								{start_sound "hit/small/weapon/smg/%1/"}
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit 
		{if rand 0.3 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/small/weapon/smg/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		ground 			2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood 			2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			ground 			2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
	}
}

