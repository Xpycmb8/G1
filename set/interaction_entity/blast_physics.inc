{"stuff"
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "shell fg"
				{impulse up 0.4 0.2 dir 1 0.5}
			else stuff "shell"
				{impulse dir 12 5 up 0.5 cx 0 0.5 cy 0 0.5}
			else stuff "rocketlauncher"
				{impulse up 0.9 0.5 dir 5 2.5}
			else stuff "zenite"
				{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
			else stuff "hmgun"
				{impulse up 0.9 0.5 dir 5 2.5}
			else stuff "bullet sm_ic"
				{impulse up 0.7 0.4 dir 3 2.5}
			else stuff "bullet big"
				{impulse up 0.6 0.4 dir 3 2.5}
			else stuff "bullet normal ap"
				{impulse up 0.5 0.3 dir 2 1.5}
			else stuff "bullet normal"
				{impulse up 0.4 0.2 dir 1 0.5}
			else stuff "bullet noview"
				{impulse dir 0.1}
			else stuff "bullet"
				{impulse up 0.4 0.2 dir 1 0.5}
			}
		}
	}
}

{"blast_physics_small"
	{on blast
		{if not linked
			{call "blast_physics"}
		}
	}
}
{"local_physics"
	{on blast
		{if not stuff "orientation_gun_check" 
			{if not linked
				{call "blast_physics"}
			}
		}
	}
	{on "blast_physics"
		(define "disable_contact_blast_0")
		(define "mass"
			(define "blast_physics"
				{if tagged "%mass"
					{if not prop "vehicle" ; fix jump vehicle
						{if min_energy %energy				
							{impulse dir (* %density %energy) }
							{tags add "%energy"}
							{tags add "%density"}
						}
					}
				}
			)		
			("blast_physics" energy(40) 		)
			("blast_physics" energy(30) 		)
			("blast_physics" energy(20) 		)
			("blast_physics" energy(15) 		)
			("blast_physics" energy(10) 		)
			("blast_physics" energy(8) 		)
			("blast_physics" energy(6)		)
			("blast_physics" energy(4)		)
			("blast_physics" energy(2.5)	)
			("blast_physics" energy(1.5)	)
			("blast_physics" energy(0.5)	)
			("blast_physics" energy(0.2) 	)
		)		
		("mass" mass(25000) density(0.000))
		("mass" mass(20000) density(0.000))
		("mass" mass(5000) density(0.0001))
		("mass" mass(4000) density(0.0001))
		("mass" mass(3000) density(0.0001))
		("mass" mass(2000) density(0.002))
		("mass" mass(1900) density(0.01))
		("mass" mass(1800) density(0.02))
		("mass" mass(1700) density(0.03))
		("mass" mass(1600) density(0.045))
		("mass" mass(1500) density(0.05))
		("mass" mass(1400) density(0.07))
		("mass" mass(1300) density(0.09))
		("mass" mass(1200) density(0.1))
		("mass" mass(1100) density(0.14))
		("mass" mass(1000) density(0.2))
		("mass" mass(900) density(0.28))
		("mass" mass(800) density(0.32))
		("mass" mass(700) density(0.4))
		("mass" mass(600) density(0.45))
		("mass" mass(500) density(0.55))
		("mass" mass(400) density(0.63))
		("mass" mass(300) density(0.71))
		("mass" mass(200) density(0.8))
		("mass" mass(150) density(0.9))
		("mass" mass(100) density(0.93))
		("mass" mass(50) density(1.1))
		("mass" mass(25) density(2.5))
		("mass" mass(10) density(3.5))
		("mass" mass(1)  density(4))
		;	}
		; (define "blast_physics"
			; {if min_mass %mass 
				; {if min_energy %energy				
		 ; ;(/ 		
		 ; ;	(* 	5 		%energy)    ;energy
		 ; ;	(/ 	%mass 	10) 	  ;mass 
		 ; ;)
		 ; ; при массе 	1500 энергии 5
		 ; ; имп 		0.1
					; ; 50 5
					; ; 0.2
					
		 ; ; (* 0.5 (+  (/ % 10)  (* 5 		(+ % 0.25))))		
				
				
					; {impulse 
							; dir 
								 ; (/ 		
									; (* 	5 		%energy)    ;energy
									; (/ 	%mass 	10) 	  	;mass 
								; )
									; cx 0 0.1 
									; cy 0 0.1
								; }
					; {tags add "%mass %energy"}
				; }
			; else min_mass 0.1
				; {impulse dir 0.01}
			; }
		; (define "blast_physics"
			; {if min_mass %mass_max 
				; {if min_energy %energy_max
					; {tags add "%mass_max"}
					; {tags add "%energy_max"}
					; %impulse_max
				; else min_energy %energy_min
					; {tags add "%energy_min"}
					; %impulse_min
				; }
			; }
		; )		
		; ("blast_physics" 
			; mass_max(1000)
			; energy_max(20) 
			; energy_min(10)
			; impulse_max({impulse dir 8 4 cx 3 1 cy 3 1}) 
			; impulse_min({impulse dir 4 1 cx 0 0.1 cy 0 0.1})
		; )
		; ("blast_physics" 
			; mass_max(500)
			; energy_max(15) 
			; energy_min(7)
			; impulse_max({impulse dir 7 4 cx 2 1 cy 2 1}) 
			; impulse_min({impulse dir 2 1 cx 0 0.1 cy 0 0.1})
		; )
		; ("blast_physics" 
			; mass_max(250)
			; energy_max(15) 
			; energy_min(7)
			; impulse_max({impulse dir 5 3 cx 2 1 cy 2 1}) 
			; impulse_min({impulse dir 4 2 cx 0 0.1 cy 0 0.1})
		; )
		; ("blast_physics" 
			; mass_max(90)
			; energy_max(3) 
			; energy_min(1.5)
			; impulse_max({impulse dir 2 1 cx 0.5 0.2 cy 0.5 0.3}) 
			; impulse_min({impulse dir 1 0.5 cx 0 0.2 cy 0 0.2})
		; )
		; ("blast_physics" 
			; mass_max(25)
			; energy_max(2) 
			; energy_min(1)
			; impulse_max({impulse dir 4 2 cx 1 0.5 cy 1 0.5}) 
			; impulse_min({impulse dir 2 1 cx 0 0.3 cy 0 0.3})
		; )
		; ("blast_physics" 
			; mass_max(10)
			; energy_max(1) 
			; energy_min(0.5)
			; impulse_max({impulse dir 0.5 0.3 cx 0 0.1 cy 0 0.1}) 
			; impulse_min({impulse dir 0.3 0.1 cx 0 0.1 cy 0 0.1})
		; )
	}
}

