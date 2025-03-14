void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

switch (c)
{
  case 1:
    if (a1 == 1)
    {
      stopwatch();
      a1compare();
    }
    else
    {
      sreset();
    }
    break;
  case 2:
    if (b1 == 1)
    {
      stopwatch2();
      a2compare();
    }
    else
    {
      sreset2();
    }
    break;
  case 3:
    if (c1 == 1)
    {
      stopwatch3();
      a3compare();
    }
    else
    {
      sreset3();
    }
    break;
  case 4:
    if (d1 == 1)
    {
      stopwatch4();
      a4compare();
    }
    else
    {
      sreset4();
    }
    break;
  default:

    break;
}