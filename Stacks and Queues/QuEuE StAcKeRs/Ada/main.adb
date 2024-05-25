--
-- Written in Ada language
--  by Alexandre Boutrik.
--
-- Algorithms and Data Structures course at UTFPR-TD
-- Assignment I due 26/May 2024.
--

-- Ada packages
with Ada.Text_IO;                       use Ada.Text_IO;
with Ada.Strings.Unbounded;             use Ada.Strings.Unbounded;

-- custom packages
with Data_Structure;                    use Data_Structure;
with Utility;                           use Utility;

procedure Main is

    -- Main procedure variables
    Input     : String (1..4096);
    Last      : Integer;

    Next_Word : Unbounded_String;
    Index     : Integer;

    Inserted  : Integer := 0;
    Sold      : Integer := 0;

    -- create the windows and the queues
    Window : Two_Stack;
    Wqueue : Two_Queue;

begin
    -- Main loop
    loop
        -- reset the input variable and the "slice" index
        Input := (others => ' ');
        Index := 1;

        -- read a line from the input
        Get_Line(Input, Last);
        --              ^ input size

        exit when Input(1..3) = "fim";

        -- remove the first word from the input
        Next_Word := To_Unbounded_String(Get_Next_Word(Input, Index));

        if Input(1..5) = "chega" then
            Chega(Wqueue,
                Get_Next_Word(Input, Index),    -- tickets
                Get_Next_Word(Input, Index),    -- name
                Inserted);

        elsif Input(1..5) = "vende" then
            Vende(Wqueue, Window,
            Get_Next_Word(Input, Index),        -- window number
            Sold);

        elsif Input(1..7) = "carrega" then
            Carrega(Window,
                Get_Next_Word(Input, Index),    -- end range
                Get_Next_Word(Input, Index),    -- start range
                Get_Next_Word(Input, Index));   -- window number

        end if;
    end loop;

    Put_Line("Ingressos vendidos:" & Sold'Image & ".");

end Main;
