using System;

    namespace labsemana3ejercicio4 {

        public struct Jugador {
            public string nombre;
            public int nivel;
            public int salud;
            public int puntaje;
            public int equipo;
        }
        
        class Program {
        static void IngresarDatos(Jugador[] Jugadores, int n) {
                for(int i = 0; i < n; i++) {
                    Console.WriteLine("Ingrese los datos para el Jugador {0}:", i + 1);
                    Console.Write("nombre: ");
                    Jugadores[i].nombre = Console.ReadLine();
                    Console.Write("Nivel: ");
                    Jugadores[i].nivel = Convert.ToInt32(Console.ReadLine());
                    Console.Write("salud: ");
                    Jugadores[i].salud = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Puntaje: ");
                    Jugadores[i].puntaje = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Equipo (1 o 2): ");
                    Jugadores[i].equipo = Convert.ToInt32(Console.ReadLine());
                }
            }
            
        static void ImprimirEstadisticas(Jugador[] Jugadores, int n) {
                for (int i = 0; i < n; i++) {
                    Console.WriteLine("Estadísticas para {0}:", Jugadores[i].nombre);
                    Console.WriteLine("Nivel: {0}", Jugadores[i].nivel);
                    Console.WriteLine("salud: {0}", Jugadores[i].salud);
                    Console.WriteLine("Puntaje: {0}", Jugadores[i].puntaje);
                    Console.WriteLine("Equipo: {0}", Jugadores[i].equipo);
                    Console.WriteLine();
                }
            }
            
        static void ActualizarEstadisticas(Jugador[] Jugadores, int n, string nombre, int nivel, int salud, int puntaje) {
                for (int i = 0; i < n; i++) {
                    if (Jugadores[i].nombre == nombre) {
                        Jugadores[i].nivel = nivel;
                        Jugadores[i].salud = salud;
                        Jugadores[i].puntaje = puntaje;
                        return;
                    }
                }
                Console.WriteLine("Error: jugador no encontrado");
            }
            
        static string DeterminarGanador(Jugador[] Jugadores, int n) {
                int equipo1Puntaje = 0;
                int equipo2Puntaje = 0;
                
                for (int i = 0; i < n; i++) {
                    if (Jugadores[i].equipo == 1) {
                        equipo1Puntaje += Jugadores[i].puntaje;
                    } else if (Jugadores[i].equipo == 2) {
                        equipo2Puntaje += Jugadores[i].puntaje;
                    }
                }
                
                if (equipo1Puntaje > equipo2Puntaje) {
                    return "Equipo 1 ganador";
                } else if (equipo2Puntaje > equipo1Puntaje) {
                    return "Equipo 2 es el ganador";
                } else {
                    return "Empate";
                }
            }

        static void JugarPartida(Jugador[] equipo1, Jugador[] equipo2, int numTurnos){
            Random random = new Random();

            for (int i = 1; i <= numTurnos; i++)
            {
                Console.WriteLine("----- Turno " + i + " -----");

                // Equipo 1 ataca
                Console.WriteLine("Equipo 1 ataca");
                int dado1 = random.Next(1, 7);
                if (dado1 <= 3) // Si el dado sale 1, 2 o 3, el equipo 1 realiza un ataque
                {
                    int indexEquipo2 = random.Next(equipo2.Length);
                    Jugador JugadorAtacado = equipo2[indexEquipo2];
                    Console.WriteLine("Ataque exitoso a " + JugadorAtacado.nombre);
                    JugadorAtacado.salud -= 10;
                    if (JugadorAtacado.salud <= 0)
                    {
                        Console.WriteLine(JugadorAtacado.nombre + " ha quedado fuera de juego");
                        equipo2 = equipo2.Where((source, index) => index != indexEquipo2).ToArray(); // Eliminar Jugador del equipo 2
                    }
                }
                else
                {
                    Console.WriteLine("El ataque ha fallado");
                }

                Console.WriteLine();

                if (equipo2.Length == 0) // Si el equipo 2 se queda sin Jugador, el equipo 1 gana
                {
                    Console.WriteLine("¡El equipo 1 ha ganado!");
                    break;
                }

                // Equipo 2 ataca
                Console.WriteLine("Equipo 2 ataca");
                int dado2 = random.Next(1, 7);
                if (dado2 <= 3) // Si el dado sale 1, 2 o 3, el equipo 2 realiza un ataque
                {
                    int indexEquipo1 = random.Next(equipo1.Length);
                    Jugador JugadorAtacado = equipo1[indexEquipo1];
                    Console.WriteLine("Ataque exitoso a " + JugadorAtacado.nombre);
                    JugadorAtacado.salud -= 10;
                    if (JugadorAtacado.salud <= 0)
                    {
                        Console.WriteLine(JugadorAtacado.nombre + " ha quedado fuera de juego");
                        equipo1 = equipo1.Where((source, index) => index != indexEquipo1).ToArray(); // Eliminar Jugador del equipo 1
                    }
                }
                else
                {
                    Console.WriteLine("El ataque ha fallado");
                }

                Console.WriteLine();

                if (equipo1.Length == 0) // Si el equipo 1 se queda sin Jugadors, el equipo 2 gana
                {
                    Console.WriteLine("¡El equipo 2 ha ganado!");
                    break;
                }
            }
        }
        static void Main(string[] args) {
                int numJugadores = 5;
                int numTurnos = 5;
                Jugador[] equipo1 = new Jugador[numJugadores];
                Jugador[] equipo2 = new Jugador[numJugadores];

                IngresarDatos(equipo1, 2);
                ImprimirEstadisticas(equipo1, 2);
                IngresarDatos(equipo2, 2);
                ImprimirEstadisticas(equipo2, 2);
                JugarPartida(equipo1, equipo2, numTurnos);


                
            }      
        }
    }