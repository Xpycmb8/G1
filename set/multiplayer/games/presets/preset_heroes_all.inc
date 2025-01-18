; == STANDARD ==
(define "standard_all"
	{common
		{unitset
			{value "heroes"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	176}		; in seconds
					{growTable	"1.0"}
					{payback
						{cp			"0 		1"}
						{restore	"2.5	2.5"}
					}
				}
				{buttons "s1"}
			}
		}
	}
	{bots
		(include "bots_heroes.inc")
	}
)

; == CUSTOM ==
(define "custom_all"
	{common
		{unitset
			{value "heroes"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	126}		; in seconds
					{growTable	"1.0"}
					{payback
						{cp			"0 		1"}
						{restore	"2.5	2.5"}
					}
				}
				{buttons "s1"}
			}
		}
	}
	{bots
		(include "bots_heroes.inc")
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:standard_50_all"
		{gameMode "standard"}
		{unitMode "all"}
		{specMode "all_normal"}
		("standard_all"			start(125) finish(300) cp(1))
		{ranked}
	}
}