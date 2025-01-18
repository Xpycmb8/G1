{"delete_60"
	{on spawn 
		{delay 60
			{delete}
		}
	}
}

{"delete_60h"
	{on spawn 
		{delay 45
			{hide 25}
		}
	}
}



{"delete_240"
	{on spawn 
		{delay 240
			{spawn "metal_crush"}
			{delete}
		}
	}
}

{"delete_200h"
	{on spawn 
		{delay 200
			{hide 35}
		}
	}
}

{"delete_360"
	{on spawn 
		{delay 360
			{hide 3}
		}
	}
}
{"delete_after_spawn"
	{on spawn
		{delay 600
			{hide 2}
		}
	}
}



{"delete_t2"
	{on spawn
		{delay 2
			{delete}
		}
	}
}

{"delet_t5"
	{on spawn
		{delay 5
			{delete}
		}
	}
}

{"delet_t5_hide"
	{on spawn
		{delay 3
			{hide 2}
		}
	}
}

{"delet_t15"
	{on spawn
		{delay 15
			{delete}
		}
	}
}


{"delet_t15_hide"
	{on spawn
		{delay 14
			{hide 5}
		}
	}
}



{"delet_t30"
	{on spawn
		{delay 30
			{hide 5}
		}
	}
}

{"delete_t5"
	{on spawn
		{delay 5
			{delete}
		}
	}
}

{"delet_t60"
	{on spawn
		{delay 60
			{hide 5}
		}
	}
}

{"delet_t120"
	{on spawn
		{delay 120
			{hide 7}
		}
	}
}
{"delet_t240"
	{on spawn
		{delay 240
			{hide 15}
		}
	}
}



{"delet_t60s"
	{on spawn
		{delay 35
			{hide 15}
		}
	}
}

{"delet_t120s"
	{on spawn
		{delay 80
			{hide 25}
		}
	}
}

{"delet_360"
	{on spawn
		{delay 240
			{hide 7}
		}
	}
}

{"delete_spawn"
	{on spawn
		{delete}
	}
}

{"delete_spawn_blast"
	{on spawn
		{start_sound "detonation/ammo"}	
		{spawn "ex_bk_ammo"  }	
		{blastwave c4 1 r0 2 r1 2}	
		{delete}
	}
}


{"delete_spawn_fire"
	{on spawn
		{if rand 0.5
			{start_sound "detonation/ammo/"}	
		}		
		{blastwave c4 1 r0 2 r1 2}	
		{fire radius 0.7 time 3 heating 1}
		{delete}
	}
}

