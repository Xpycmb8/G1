{bone "upgrade_right_zenitco"
	{parameters "Voxels=0;"}
	{Position -0.0082458	-0.201189	-0.0148362}
	{bone "fx_laser_set_r_zenitco"
		{Matrix34
			-0.000180083	1	0
			0.00018032	0	-1
			-1	-0.0001801	-0.00018032
			-0.241006	0.904937	0.238825
		}
	}
	{bone "zenitco_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.06687	1.69119	0.630669
		}
		{bone "zenitco_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				0.99384	1.67641	-0.0642891
			}
			{VolumeView "zenitco_r_ui.ply"}
			{bone "zenitco_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136638	0.0741324	-0.145817
				}
				{VolumeView "zenitco_r_light_on_ui.ply"}
			}
			{bone "zenitco_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136507	-0.109508	-0.145817
				}
				{VolumeView "zenitco_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_zenitco"
		{Matrix34
			-0.000180083	1	0
			0.00018032	0	-1
			-1	-0.0001801	-0.00018032
			0.00203428	0.861387	0.59198
		}
	}
	{bone "zenitco_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0269066	0.202049	0.464541
		}
		{visibility 0}
		{LODView
			{VolumeView "zenitco_r.ply"}
			{VolumeView "zenitco_r_lod1.ply"}
			{VolumeView "zenitco_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_tactical_laser2"
	{parameters "Voxels=0;"}
	{Position -0.00560144	0.276954	-0.00370294}
	{bone "fx_laser_set_r_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.298229	0.751893	0.133945
		}
	}
	{bone "tactical_laser2_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.58006	2.03831	0.292361
		}
		{bone "tactical_laser2_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47807	1.98721	-0.0762092
			}
			{VolumeView "tactical_laser2_r_ui.ply"}
			{bone "tactical_laser2_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0016225	0.00722075	-0.00276136
				}
				{VolumeView "tactical_laser2_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser2_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.0191546	-0.736453	0.102905
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser2_r.ply"}
			{VolumeView "tactical_laser2_r_lod1.ply"}
			{VolumeView "tactical_laser2_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_tactical_laser"
	{parameters "Voxels=0;"}
	{Position -0.00548792	0.224195	-0.00559062}
	{bone "fx_laser_set_r_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.159248	0.113134	0.32853
		}
	}
	{bone "tactical_laser_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.58006	1.79569	0.658123
		}
		{bone "tactical_laser_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47807	1.98721	-0.0762093
			}
			{VolumeView "tactical_laser_r_ui.ply"}
			{bone "tactical_laser_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162256	0.00722075	-0.0027613
				}
				{VolumeView "tactical_laser_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			-0.00161111	-0.286011	0.127223
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser_r.ply"}
			{VolumeView "tactical_laser_r_lod1.ply"}
			{VolumeView "tactical_laser_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_peq15"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.044858	0.176676	-0.00109893
	}
	{bone "fx_light_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.388003	1.29834	0.275421
		}
	}
	{bone "fx_laser_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.341393	1.04633	0.246616
		}
	}
	{bone "caps_light_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0.984808	0.173648
			0	0.173648	-0.984808
			-1	0	0
			-0.332621	0.921367	0.32953
		}
		{VolumeView "caps_light_r.ply"}
	}
	{bone "caps_laser_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	1
			-1	0	0
			0	-1	0
			0.308772	0.792223	0.328875
		}
		{VolumeView "caps_laser_r.ply"}
	}
	{bone "peq15_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.32759	1.83171	0.412333
		}
		{bone "peq15_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.25555	1.95294	-0.0748935
			}
			{VolumeView "peq15_r_ui.ply"}
			{bone "peq15_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159293	0.00704479	-0.00404626
				}
				{VolumeView "peq15_r_light_on_ui.ply"}
			}
			{bone "peq15_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00158083	0.00677776	-0.00404629
				}
				{VolumeView "peq15_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "peq15_r"
		{parameters "CommonMesh;"}
		{Position 0.00922179	-0.0184131	-0.0291555}
		{visibility 0}
		{LODView
			{VolumeView "peq15_r.ply"}
			{VolumeView "peq15_r_lod1.ply"}
			{VolumeView "peq15_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_peq10"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00453591	-0.0718284	-0.00483823
	}
	{bone "an_peq10_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	1
			0	1	0
			-1	0	0
			0.0047884	-0.204135	0.0813742
		}
		{visibility 0}
		{LODView
			{VolumeView "an_peq10_r.ply"}
			{VolumeView "an_peq10_r_lod1.ply"}
			{VolumeView "an_peq10_r_lod2.ply"}
		}
		{bone "caps_front_r"
			{parameters "CommonMesh;"}
			{Matrix34
				0.0871559	0.996195	0
				-0.996195	0.0871559	0
				0	0	1
				0.27289	0.934131	-0.00422153
			}
			{VolumeView "caps_front_r.ply"}
		}
	}
	{bone "fx_laser_set_r_peq10"
		{Matrix34
			0.000315677	1	0
			-1	0.000315681	-0.000311374
			-0.000311374	0	1
			-0.177624	0.921118	0.367409
		}
	}
	{bone "peq10_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.11889	1.67564	0.376042
		}
		{bone "peq10_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.11177	1.87533	-0.0719172
			}
			{VolumeView "peq10_r_ui.ply"}
			{bone "peq10_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00152862	0.0829289	-0.163119
				}
				{VolumeView "peq10_r_light_on_ui.ply"}
			}
			{bone "peq10_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00152707	-0.122502	-0.163119
				}
				{VolumeView "peq10_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_peq10"
		{Matrix34
			0.000315677	1	0
			-1	0.000315681	-0.000311374
			-0.000311374	0	1
			0.184977	0.921116	0.367408
		}
	}
}
{bone "upgrade_right_liner"
	{parameters "Voxels=0;"}
	{Position -0.000106037	0.0382538	0.00103194}
	{bone "fx_laser_set_r_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0131749	1.32232	0.355102
		}
	}
	{bone "liner_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.54783	-2.05824	0.547827
		}
		{bone "liner_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.41895	1.90772	-0.073161
			}
			{VolumeView "liner_r_ui.ply"}
			{bone "liner_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00155771	0.00693226	-0.00265098
				}
				{VolumeView "liner_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "liner_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00768405	0.259694	-0.0220748
		}
		{visibility 0}
		{LODView
			{VolumeView "liner_r.ply"}
			{VolumeView "liner_r_lod1.ply"}
			{VolumeView "liner_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_lasercylinder4"
	{parameters "Voxels=0;"}
	{Position -0.00399268	0.154616	-9.90033e-05}
	{bone "lasercylinder4_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.61232	-2.07954	0.382686
		}
		{bone "lasercylinder4_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47807	1.98721	-0.0762092
			}
			{VolumeView "lasercylinder4_r_ui.ply"}
			{bone "lasercylinder4_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162256	0.00722075	-0.00276136
				}
				{VolumeView "lasercylinder4_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_laser_set_r_lasercylinder4"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00253397	0.834443	0.311328
		}
	}
	{bone "laser_rail_r_lasercylinder4"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0276874	-0.0536366	0.0481602
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder4.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod2.ply"}
		}
		{bone "lasercylinder4_r"
			{parameters "CommonMesh;"}
			{Position 0.270354	-0.267118	-0.0250309}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder4_r.ply"}
				{VolumeView "lasercylinder4_r_lod1.ply"}
				{VolumeView "lasercylinder4_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_lasercylinder3"
	{parameters "Voxels=0;"}
	{Position -0.00504926	0.159935	-0.00361913}
	{bone "fx_laser_set_r_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00253391	0.729432	0.311328
		}
	}
	{bone "lasercylinder3_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.61232	-2.07954	0.382686
		}
		{bone "lasercylinder3_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47807	1.98721	-0.0762092
			}
			{VolumeView "lasercylinder3_r_ui.ply"}
			{bone "lasercylinder3_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0016225	0.00722075	-0.00276136
				}
				{VolumeView "lasercylinder3_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder3"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0281115	-0.053638	0.0501711
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder3.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod2.ply"}
		}
		{bone "lasercylinder3_r"
			{parameters "CommonMesh;"}
			{Position 0.241947	-0.261763	-0.0280444}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder3_r.ply"}
				{VolumeView "lasercylinder3_r_lod1.ply"}
				{VolumeView "lasercylinder3_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_lasercylinder1"
	{parameters "Voxels=0;"}
	{Position -0.00502607	0.162289	-3.43919e-05}
	{bone "fx_laser_set_r_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00847679	1.11602	0.307988
		}
	}
	{bone "lasercylinder1_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.61232	-2.07954	0.382686
		}
		{bone "lasercylinder1_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47807	1.98721	-0.0762092
			}
			{VolumeView "lasercylinder1_r_ui.ply"}
			{bone "lasercylinder1_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0016225	0.00722075	-0.00276142
				}
				{VolumeView "lasercylinder1_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder1"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0284421	-0.0536375	0.0466311
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod2.ply"}
		}
		{bone "lasercylinder1_r"
			{parameters "CommonMesh;"}
			{Position 0.250168	-0.261446	-0.0368719}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder1_r.ply"}
				{VolumeView "lasercylinder1_r_lod1.ply"}
				{VolumeView "lasercylinder1_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_laser5mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0363744	-0.340961	0.00659579
	}
	{bone "fx_light_set_r_laser5mw"
		{Matrix34
			0.000315681	1	0
			-1	0.000315679	-0.000311375
			-0.000311374	0	1
			0.023315	1.02274	0.372442
		}
	}
	{bone "fx_laser_set_r_laser5mw"
		{Matrix34
			0.000315681	1	0
			-1	0.000315679	-0.000311375
			-0.000311374	0	1
			-0.0807576	1.00156	0.22223
		}
	}
	{bone "laser5mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.17584	2.40252	0.413049
		}
		{bone "laser5mw_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.17809	1.98721	-0.0762079
			}
			{VolumeView "laser5mw_r_ui.ply"}
			{bone "laser5mw_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00161982	0.0878763	-0.172851
				}
				{VolumeView "laser5mw_r_light_on_ui.ply"}
			}
			{bone "laser5mw_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00161815	-0.12981	-0.172851
				}
				{VolumeView "laser5mw_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser5mw_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	-0.000678402
			1	0	0
			0	-0.000678398	-1
			0.0305917	0.286786	0.116053
		}
		{visibility 0}
		{LODView
			{VolumeView "laser5mw_r.ply"}
			{VolumeView "laser5mw_r_lod1.ply"}
			{VolumeView "laser5mw_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_laser1mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00223458	-0.26796	-0.000373423
	}
	{bone "fx_laser_set_r_laser1mw"
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.00234318	0.543114	0.731055
		}
	}
	{bone "laser1mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.22377	2.10322	0.377181
		}
		{bone "laser1mw_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.11892	1.8874	-0.0723803
			}
			{VolumeView "laser1mw_r_ui.ply"}
			{bone "laser1mw_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00153846	0.0834627	-0.164169
				}
				{VolumeView "laser1mw_r_light_on_ui.ply"}
			}
			{bone "laser1mw_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00153691	-0.123291	-0.16417
				}
				{VolumeView "laser1mw_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_laser1mw"
		{Matrix34
			0.000315677	1	0
			-1	0.00031568	-0.000311372
			-0.000311377	0	1
			0.00195536	1.29189	0.372995
		}
	}
	{bone "laser_1mw_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			0.00396416	0.0588915	0.118618
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_1mw_r.ply"}
			{VolumeView "laser_1mw_r_lod1.ply"}
			{VolumeView "laser_1mw_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_flashlight_sf"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00151372	0.248752	-0.00553972
	}
	{bone "fx_light_set_r_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00437257	1.17743	0.5291
		}
	}
	{bone "flashlight_sf_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.5012	2.05194	0.246306
		}
		{bone "flashlight_sf_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.43113	1.72594	-0.0737883
			}
			{VolumeView "flashlight_sf_r_ui.ply"}
			{bone "flashlight_sf_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.001571	0.00699139	-0.00267369
				}
				{VolumeView "flashlight_sf_r_light_on_ui.ply"}
			}
		}
	}
	{bone "flashlight_sf_r"
		{parameters "CommonMesh;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	-1
			0	0	-0.000485659
		}
		{visibility 0}
		{LODView
			{VolumeView "flashlight_sf_r.ply"}
			{VolumeView "flashlight_sf_r_lod1.ply"}
			{VolumeView "flashlight_sf_r_lod2.ply"}
		}
	}
}