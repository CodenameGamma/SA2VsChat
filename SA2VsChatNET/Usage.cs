using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using Newtonsoft.Json;


namespace CrowdControl
{
    public class Example : IDisposable
    {
        private readonly SimpleTCPClient _client = new SimpleTCPClient();

        public Example() => _client.RequestReceived += RequestReceived;

        ~Example() => Dispose(false);

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            if (disposing) { _client.Dispose(); }
        }

        private void RequestReceived(SimpleTCPClient.Request request)
        {

            Console.WriteLine($"Got an effect request [{request.id}:{request.code}].");
            Log.Message($"Got an effect request [{request.id}:{request.code}].");
            if (false)
            {
                Console.WriteLine($"Game Not Ready - Retry Effect - [{request.id}:{request.code}].");
                Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                return;
            }
            if (!SA2VsChatNET.SA2VsChat.IsInGame())
            {
                Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
            }
            switch (request.code)
            {
                case "ringFive":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(1))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "ringTen":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(3))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "ringTwenty":
                    {
                        SA2VsChatNET.SA2VsChat.GiveItem(4);

                        //try to do the thing
                        Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        break;
                    }
                case "shield":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(5))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "1up":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(2))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "bomb":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(6))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "health":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(7))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "magnet":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(8))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "invincibility":
                    {
                        if (SA2VsChatNET.SA2VsChat.GiveItem(10))
                        {

                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "omochao":
                    {
                        if (SA2VsChatNET.SA2VsChat.SpawnOmochao())
                        {
                          
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "stop":
                    {
                        if (SA2VsChatNET.SA2VsChat.Stop())
                        {
                          
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "GottaGoFast":
                    {
                        if (SA2VsChatNET.SA2VsChat.IsInGame())
                        {
                            SA2VsChatNET.SA2VsChat.GottaGoFast();
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "TsafOgAttog":
                    {
                        if (SA2VsChatNET.SA2VsChat.IsInGame())
                        {
                            SA2VsChatNET.SA2VsChat.TsafOgAttog();
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "SuperJump":
                    {
                        if (SA2VsChatNET.SA2VsChat.SuperJump())
                        {
                           
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                /*case "PmujRepus":
                    {
                        if (SA2VsChatNET.SA2VsChat.SuperJump())
                        {
                       
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }*/
                case "TimeStop":
                    {
                        if (SA2VsChatNET.SA2VsChat.TimeStop())
                        {
                            
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "Die":
                    {
                        if (SA2VsChatNET.SA2VsChat.Die("Crowd Control"))
                        {
                            
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "Win":
                    {
                        if (SA2VsChatNET.SA2VsChat.Win("Crowd Control"))
                        {
                            
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {

                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }

                case "Grow":
                    {
                        if (SA2VsChatNET.SA2VsChat.Grow())
                        {
                            Console.WriteLine("Effect Done! - Grow");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - Grow");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }

                case "Shrink":
                    {
                        if (SA2VsChatNET.SA2VsChat.Shrink())
                        {
                            Console.WriteLine("Effect Done! - Shrink");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - Shrink");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }

                case "HighGravity":
                    {
                        if (SA2VsChatNET.SA2VsChat.HighGravity())
                        {
                            Console.WriteLine("Effect Done! - HighGravity");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - HighGravity");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "LowGravity":
                    {
                        if (SA2VsChatNET.SA2VsChat.LowGravity())
                        {
                            Console.WriteLine("Effect Done! - LowGravity");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - LowGravity");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "SpeedUp":
                    {
                        if (SA2VsChatNET.SA2VsChat.SpeedUp())
                        {
                            Console.WriteLine("Effect Done! - SpeedUp");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - SpeedUp");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "SlowDown":
                    {
                        if (SA2VsChatNET.SA2VsChat.SlowDown())
                        {
                            Console.WriteLine("Effect Done! - SlowDown");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - SlowDown");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "HealBoss":
                    {
                        if (SA2VsChatNET.SA2VsChat.HealBoss())
                        {
                            Console.WriteLine("Effect Done! - HealBoss");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - HealBoss");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "Confuse":
                    {
                        if (SA2VsChatNET.SA2VsChat.Confuse())
                        {
                            Console.WriteLine("Effect Done! - Confuse");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - Confuse");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "Earthquake":
                    {
                        if (SA2VsChatNET.SA2VsChat.Earthquake())
                        {
                            Console.WriteLine("Effect Done! - Earthquake");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - Earthquake");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "ToggleChaoKey":
                    {
                        if (SA2VsChatNET.SA2VsChat.ToggleChaoKey())
                        {
                            Console.WriteLine("Effect Done! - HealBoss");
                            //try to do the thing
                            Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        }
                        else
                        {
                            Console.WriteLine("Effect retried! - HealBoss");
                            Respond(request, SimpleTCPClient.EffectResult.Retry).Forget();
                        }
                        break;
                    }
                case "ChangeCharacterSonic":
                    {
                        SA2VsChatNET.SA2VsChat.ChangeCharacter(0);

                        //try to do the thing
                        Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        break;
                    }
                case "ChangeCharacterShadow":
                    {
                        SA2VsChatNET.SA2VsChat.ChangeCharacter(1);

                        //try to do the thing
                        Respond(request, SimpleTCPClient.EffectResult.Success).Forget(); //or failtemporary
                        break;
                    }
                default:
                    {
                        Log.Message($"Effect {request.code} not found.");
                        //could not find the effect
                        Respond(request, SimpleTCPClient.EffectResult.Unavailable).Forget();
                        return;
                    }
            }


        }

        private async Task<bool> Respond(SimpleTCPClient.Request request, SimpleTCPClient.EffectResult result, string message = "")
        {
            try
            {
                return await _client.Respond(new SimpleTCPClient.Response
                {
                    id = request.id,
                    status = result,
                    message = message
                });
            }
            catch (Exception e)
            {
                Log.Error(e);
                return false;
            }
        }
    }
}
