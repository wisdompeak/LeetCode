for (int subset=state; subset>0; subset=(subset-1)&state)
{
   DoSomething(subset);
}
