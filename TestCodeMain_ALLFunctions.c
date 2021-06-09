int main(void)
{
    init();
    LED(1);
    _delay_ms(2000);
    LED(3);
    _delay_ms(2000);
    LED(2);
    _delay_ms(2000);
    LED(4);
    _delay_ms(2000);
    while(1)
    {
		while(TreeAmount > TreeCounter)		//Telt tot de AGV het aantal bomen in die rij heeft gehad
		{
        double distanceUS1 = distance(ultra_1_trigger);
 //    double distanceUS2 = distance(ultra_2_trigger);
        LED(5);
        while((distanceUS1 < distanceToTree)==0)
        {
            Vooruit(10);
            LED(1);
            distanceUS1 = distance(ultra_1_trigger);
            //  distanceUS2 = distance(ultra_2_trigger);
        }
        LED(6);
        _delay_ms(1000);
		Vooruit(200);		//Na deze afstand moet de AGV voorbij de boom zijn die net gedetecteerd is
		TreeCounter++;
		}

    }
	LED(1);
	Vooruit(300); 		//Deze afstand is afhankelijk hoe lang de baan is
	Linksaf(512);		//Gaat naar links naar het volgende pad
	while(TreeAmount > TreeCounter)
	
    return 0;
}