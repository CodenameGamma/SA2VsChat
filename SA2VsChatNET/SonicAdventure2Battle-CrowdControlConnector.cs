using System;
using System.Collections.Generic;
using System.Security.Cryptography;
using CrowdControl.Common;
using JetBrains.Annotations;
using ConnectorType = CrowdControl.Common.ConnectorType;

namespace CrowdControl.Games.Packs
{
    [UsedImplicitly]
    public class SonicAdventure2Battle : SimpleTCPPack
    {
        public override string Host => "127.0.0.1";

        public override ushort Port => 58430;

        public SonicAdventure2Battle([NotNull] IPlayer player, [NotNull] Func<CrowdControlBlock, bool> responseHandler, [NotNull] Action<object> statusUpdateHandler) : base(player, responseHandler, statusUpdateHandler) { }

        public override Game Game { get; } = new Game(87, "Sonic Adventure 2", "SonicAdventure2", "PC", ConnectorType.SimpleTCPConnector);

        public override List<Effect> Effects { get; } = new List<Effect>
        {
            //RRP (recommended retail price)
            new Effect("Give 5 Rings", "ringFive"),// Gives 5 Rings
            new Effect("Give 10 Rings", "ringTen"),// Gives 10 Rings
            new Effect("Give 20 Rings", "ringTwenty"),// Gives 20 Rings

            new Effect("Give Shield", "shield"),//Gives Green Shield
            new Effect("Give Magnet Shield", "magnet"), //Gives Maget Shield
            new Effect("Give 1Up", "1up"),//Gives the player a 1 Up.
            new Effect("Give Bomb", "bomb"), //Gives the player a bomb that destories near by Enemies
            new Effect("Give Health", "health"), //Restores the Player Health (When in Mech Stages ONLY)
            new Effect("Give Invincibility", "invincibility"), //Gives the Player Invincibility

            new Effect("Spawn Omochao", "omochao"), //Spawns an Omochao to give (unwanted) Advice.

            new Effect("Stop all movement", "stop"), //Stops the players momentum no matter what state it's in.
            new Effect("Shove", "GottaGoFast"), //Shoot the player forward with a burst of Speed
            new Effect("Reverse", "TsafOgAttog"),//Opposite of Shove, Send the player Back with a burst of speed.
            new Effect("SuperJump", "SuperJump"), //Sends the player into the Air.
            //new Effect("PmujRepus", "PmujRepus"),

            new Effect("Time Stop!", "TimeStop"), //Stops time for 15 seconds. 
            new Effect("Confuse", "Confuse"), //Confuses the player to move in a random direction for a sec.
            new Effect("Heal Boss", "HealBoss"), //Heals the boss (Only usable on Boss Stages)
            new Effect("Earthquake", "Earthquake"), //Stops the player for a second if they're on the ground. 
            new Effect("Die", "Die"),//Kills the Player
            new Effect("Win", "Win"),//Moves onto the Next Stage 

            new Effect("Grow", "Grow"), //Make my Sonic Grow! (15 seconds)
            new Effect("Shrink", "Shrink"), //Realistic Perportioned Headgehog (15 Seconds)
            new Effect("High Gravity", "HighGravity"), //Makes it harder to jump (15 Seconds)
            new Effect("Low Gravity", "LowGravity"),//Moon Jump! (15 Seconds)
            new Effect("Speed Up", "SpeedUp"), //Run Berry, Run! Faster Forward movement (15 Seconds)
            new Effect("Slow Down", "SlowDown"), //They Took his speed! Slow (15 Seconds)

            new Effect("Give/Take Chao Key", "ToggleChaoKey") //Toggle the Chao Key 



        };
    }

      
}
