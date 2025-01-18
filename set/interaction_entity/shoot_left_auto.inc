{if tagged "0_auto"
	{tags add "1_auto"}
	{tags remove "0_auto"}
else tagged "1_auto"
	{start_sound "weapon/shell_eject/shell12"}	
	{tags add "reset"}
	{tags remove "1_auto"}
	{tags add "0_auto"}
}