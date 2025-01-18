{"distant_small_set"
	{on spawn
		{impulse up 0 rnd_dir 0 forward 200 com  }
		{delay 2 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "construction"
			{start_sound "distant/build/small/"}	
		}
		{if effector "fence"
			{start_sound "distant/fence/small/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

; {"distant_opened"
	; {on spawn
		; {impulse forward 3 com  }
		; {delay 0.4 {delete}}
	; }
	; {on contact sync
		; {if not effector "human"		
			; {delete}
		; }
	; }
	; {on ground_hit sync
		; {delete}
	; }
; }





{"distant_small_grass"
	{on spawn
		{impulse up 0 rnd_dir 0 forward 25 com  }
		{delay 0.1 {delete}}
	}
}

{"distant_small_grass_set"
	{on spawn
		{spawn "distant_small_grass" "emit00" x}
		{spawn "distant_small_grass" "emit01" x}
		{spawn "distant_small_grass" "emit02" x}
		{spawn "distant_small_grass" "emit03" x}
		{spawn "distant_small_grass" "emit04" x}
		{spawn "distant_small_grass" "emit05" x}
		{spawn "distant_small_grass" "emit06" x}
		{spawn "distant_small_grass" "emit07" x}
		{delay 0 {delete}}
	}
}

{"distant_big_grass"
	{on spawn
		{impulse up 0 rnd_dir 0 forward 80 com  }
		{delay 1 {delete}}
	}
}

{"distant_big_grass_set"
	{on spawn
		{spawn "distant_big_grass" "emit00" x}
		{spawn "distant_big_grass" "emit01" x}
		{spawn "distant_big_grass" "emit02" x}
		{spawn "distant_big_grass" "emit03" x}
		{spawn "distant_big_grass" "emit04" x}
		{spawn "distant_big_grass" "emit05" x}
		{spawn "distant_big_grass" "emit06" x}
		{spawn "distant_big_grass" "emit07" x}
		{delay 0 {delete}}
	}
}



{"distant_small"
	{on spawn
		{spawn "distant_small_set" "emit00" x}
		{spawn "distant_small_set" "emit01" x}
		{spawn "distant_small_set" "emit02" x}
		{spawn "distant_small_set" "emit03" x}
		{spawn "distant_small_set" "emit04" x}
		{spawn "distant_small_set" "emit05" x}
		{spawn "distant_small_set" "emit06" x}
		{spawn "distant_small_set" "emit07" x}
		{delay 0 {delete}}
	}
}

{"distant_small_gun"
	{on spawn
		{spawn "distant_small_set_gun" "emit00" x}
		{spawn "distant_small_set_gun" "emit01" x}
		{spawn "distant_small_set_gun" "emit02" x}
		{spawn "distant_small_set_gun" "emit03" x}
		{spawn "distant_small_set_gun" "emit04" x}
		{spawn "distant_small_set_gun" "emit05" x}
		{spawn "distant_small_set_gun" "emit06" x}
		{spawn "distant_small_set_gun" "emit07" x}
		{delay 0 {delete}}
	}
}


{"distant_small_expl"
	{on spawn
		{spawn "distant_small_set_expl" "emit00" x}
		{spawn "distant_small_set_expl" "emit01" x}
		{spawn "distant_small_set_expl" "emit02" x}
		{spawn "distant_small_set_expl" "emit03" x}
		{spawn "distant_small_set_expl" "emit04" x}
		{spawn "distant_small_set_expl" "emit05" x}
		{spawn "distant_small_set_expl" "emit06" x}
		{spawn "distant_small_set_expl" "emit07" x}
		{delay 0 {delete}}
	}
}

{"distant_big_expl"
	{on spawn
		{spawn "distant_small_set_expl" "emit00" x}
		{spawn "distant_small_set_expl" "emit01" x}
		{spawn "distant_small_set_expl" "emit02" x}
		{spawn "distant_small_set_expl" "emit03" x}
		{spawn "distant_small_set_expl" "emit04" x}
		{spawn "distant_small_set_expl" "emit05" x}
		{spawn "distant_small_set_expl" "emit06" x}
		{spawn "distant_small_set_expl" "emit07" x}
		{delay 0 {delete}}
	}
}


{"distant_small_set_gun"
	{on spawn
		{gravity 0}
		{impulse up 0 rnd_dir 0 forward 300 com  }		
		{tags add "first"}
		{delay 0.5 
			{tags remove "first"}
		}
		{delay 1.5 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/gun/first"}	
			else
				{start_sound "distant/build/gun/end"}	
			}
		}
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/gun/first"}	
			else
				{start_sound "distant/build/gun/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/gun/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}


{"distant_small_set_gun_invert"
	{on spawn
		{gravity -1}
		{volumes disable contact}	
		{delay 0.4
			{volumes enable contact}	
		}
		{impulse up 8 rnd_dir 0 forward 120 com  }		
		{tags add "first"}
		{delay 1 
			{tags remove "first"}
		}
		{delay 1.5 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/gun/first"}	
			else
				{start_sound "distant/build/gun/end"}	
			}
		}
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/gun/first"}	
			else
				{start_sound "distant/build/gun/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/gun/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}


{"distant_small_set_expl"
	{on spawn
		{gravity 0}
		{impulse up 0 rnd_dir 0 forward 300 com  }		
		{tags add "first"}
		{delay 0.5 
			{tags remove "first"}
		}
		{delay 3 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/small_expl/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

{"distant_small_set_expl_invert"
	{on spawn
		{gravity -1}
		{volumes disable contact}	
		{delay 0.4
			{volumes enable contact}	
		}
		{impulse up 8 rnd_dir 0 forward 120 com  }		
		{tags add "first"}
		{delay 1 
			{tags remove "first"}
		}
		{delay 3 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/small_expl/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}


{"distant_big_set_expl"
	{on spawn
		{gravity 0}
		{impulse up 0 rnd_dir 0 forward 350 com  }		
		{tags add "first"}
		{delay 0.3 
			{tags remove "first"}
		}
		{delay 3 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/big_expl/first"}	
			else
				{start_sound "distant/build/big_expl/end"}	
			}
		}
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/big_expl/first"}	
			else
				{start_sound "distant/build/big_expl/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/big_expl/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

{"distant_big_set_expl_invert"
	{on spawn
		{gravity -1}
		{volumes disable contact}	
		{delay 0.3
			{volumes enable contact}	
		}
		{impulse up 8 rnd_dir 0 forward 210 com  }		
		{tags add "first"}
		{delay 1 
			{tags remove "first"}
		}
		{delay 3 {delete}}
	}
	{on contact ;угасание звука по таймеру
		{if effector "big_build"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "construction"
			{if tagged "first"
				{start_sound "distant/build/small_expl/first"}	
			else
				{start_sound "distant/build/small_expl/end"}	
			}
		}
		{if effector "fence"
			{start_sound "distant/fence/small_expl/"}	
		}
		{delete}
	}
	{on ground_hit
		{delete}
	}
}

{"atgm_warning"
	{on spawn
		{gravity -1}
		{volumes disable contact}	
		{delay 0.2
			{volumes enable contact}	
		}
		{impulse forward 210 com  }		
		{delay 2 {delete}}
	}
}

