



{"steel"
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}	
	; {on "fly"
		; {if altitude 15
			; {gravity 1}
		; else altitude 6
			; {gravity 0.1}
		; else altitude 1.5
			; {impulse rnd_dir 2 cx 2 1 cy 2 1 }
			; {gravity -0.1}
		; else altitude 0.2
			; {gravity -4}
		; }
		; {delay_effect 0.04 "fly"}
	; }
	; {on "up_fly"
		; {call "fly"}
		; {delay 3
			; {gravity 1}
			; {spawn "gravi_hit"}
			; {blastwave c4 10 r0 3 r1 3}	
			; {kill_delay "fly"}
		; }
		; {impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	; }
}

{"armor"
	{on spawn
	}
	; {on bullet_hit 
		; {if stuff "bullet big"
			; {if rand 0.5
				; {spawn "metal_crush"}
				; {delete}
			; }
		; else stuff "zenite"			
			; {if rand 0.1
				; {spawn "metal_crush"}
				; {delete}
			; }
		; else stuff "heavy_zenite"			
			; {if rand 0.7
				; {spawn "metal_crush"}
				; {delete}
			; }
		; else stuff "bullet"			
			; {if rand 0.1
				; {spawn "metal_crush"}
				; {delete}
			; }
		; }
	; }
	{on contact
		{if effector "dummy"
			{spawn "metal_crush"}
			{delete}
		}
	}
	; {on "fly"
		; {if altitude 15
			; {gravity 1}
		; else altitude 6
			; {gravity 0.1}
		; else altitude 1.5
			; {impulse rnd_dir 2 cx 2 1 cy 2 1 }
			; {gravity -0.1}
		; else altitude 0.2
			; {gravity -4}
		; }
		; {delay_effect 0.04 "fly"}
	; }
	; {on "up_fly"
		; {call "fly"}
		; {delay 3
			; {gravity 1}
			; {spawn "gravi_hit"}
			; {blastwave c4 10 r0 3 r1 3}	
			; {kill_delay "fly"}
		; }
		; {impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	; }
}
{"carpet"
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
	{on "fly"
		{if altitude 15
			{gravity 1}
		else altitude 6
			{gravity 0.1}
		else altitude 1.5
			{impulse rnd_dir 2 cx 2 1 cy 2 1 }
			{gravity -0.1}
		else altitude 0.2
			{gravity -4}
		}
		{delay_effect 0.04 "fly"}
	}
	{on "up_fly"
		{call "fly"}
		{delay 3
			{gravity 1}
			{spawn "gravi_hit"}
			{blastwave c4 10 r0 3 r1 3}	
			{kill_delay "fly"}
		}
		{impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	}
}
{"vehicle"}
{"steel_arm"}
{"wood"
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
	{on "fly"
		{if altitude 15
			{gravity 1}
		else altitude 6
			{gravity 0.1}
		else altitude 1.5
			{impulse rnd_dir 2 cx 2 1 cy 2 1 }
			{gravity -0.1}
		else altitude 0.2
			{gravity -4}
		}
		{delay_effect 0.04 "fly"}
	}
	{on "up_fly"
		{call "fly"}
		{delay 3
			{gravity 1}
			{spawn "gravi_hit"}
			{blastwave c4 10 r0 3 r1 3}	
			{kill_delay "fly"}
		}
		{impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	}
}
{"misc"
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
	{on "fly"
		{if altitude 15
			{gravity 1}
		else altitude 6
			{gravity 0.1}
		else altitude 1.5
			{impulse rnd_dir 2 cx 2 1 cy 2 1 }
			{gravity -0.1}
		else altitude 0.2
			{gravity -4}
		}
		{delay_effect 0.04 "fly"}
	}
	{on "up_fly"
		{call "fly"}
		{delay 3
			{gravity 1}
			{spawn "gravi_hit"}
			{blastwave c4 10 r0 3 r1 3}	
			{kill_delay "fly"}
		}
		{impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	}
}
{"flesh"
	{on spawn
		{if min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
}
{"concrete"	
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
	{on "fly"
		{if altitude 15
			{gravity 1}
		else altitude 6
			{gravity 0.1}
		else altitude 1.5
			{impulse rnd_dir 2 cx 2 1 cy 2 1 }
			{gravity -0.1}
		else altitude 0.2
			{gravity -4}
		}
		{delay_effect 0.04 "fly"}
	}
	{on "up_fly"
		{call "fly"}
		{delay 3
			{gravity 1}
			{spawn "gravi_hit"}
			{blastwave c4 10 r0 3 r1 3}	
			{kill_delay "fly"}
		}
		{impulse up 1 rnd_dir 2 cx 5 1 cy 5 1 }
	}
}
{"sand"
	{on spawn
		{if min_mass 24999
			{tags add "25000"}
		else min_mass 19999
			{tags add "20000"}
		else min_mass 4999
			{tags add "5000"}
		else min_mass 3999
			{tags add "4000"}
		else min_mass 2999
			{tags add "3000"}
		else min_mass 1999
			{tags add "2000"}
		else min_mass 1899
			{tags add "1900"}
		else min_mass 1799
			{tags add "1800"}
		else min_mass 1699
			{tags add "1700"}
		else min_mass 1599
			{tags add "1600"}
		else min_mass 1499
			{tags add "1500"}
		else min_mass 1399
			{tags add "1400"}
		else min_mass 1299
			{tags add "1200"}
		else min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
}
{"ice"}
{"gas"}
{"wound_glass"}
{"wound_glass_small"}
{"wound_lamp"}
{"kevlar"
	{on spawn
		{if min_mass 1099
			{tags add "1100"}
		else min_mass 999
			{tags add "1000"}
		else min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
}
{"kevlar_human"}
{"glass"
	{on spawn
		{if min_mass 899
			{tags add "900"}
		else min_mass 799
			{tags add "800"}
		else min_mass 699
			{tags add "700"}
		else min_mass 599
			{tags add "600"}
		else min_mass 499
			{tags add "500"}
		else min_mass 399
			{tags add "400"}
		else min_mass 299
			{tags add "300"}
		else min_mass 199
			{tags add "200"}
		else min_mass 149
			{tags add "150"}
		else min_mass 99
			{tags add "100"}
		else min_mass 49
			{tags add "50"}
		else min_mass 24
			{tags add "25"}
		else min_mass 9
			{tags add "10"}
		}
	}
}

