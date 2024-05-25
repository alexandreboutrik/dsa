with Ada.Text_IO;                       use Ada.Text_IO;
with Ada.Integer_Text_IO;               use Ada.Integer_Text_IO;

package body Utility is

    function Get_Next_Word (Source: String; Start_Index: in out Integer)
    return String is
        Word        : String(1..Source'Length);
        Word_Length : Integer := 0;
        Word_Found  : Boolean := False;
    begin
        for I in Start_Index .. Source'Last loop
            if Source(I) /= ' ' then
                Word_Found        := True;
                Word_Length       := Word_Length + 1;
                Word(Word_Length) := Source(I);
            elsif Word_Found then
                exit;
            end if;
        end loop;

        Start_Index := Start_Index + Word_Length + 1;
        return Word(1..Word_Length);
    end;

    procedure Chega (Wqueue: in out Two_Queue; Ticket: String; Name: String;
    Inserted: in out Integer) is
        P: Person;
    begin
        P.Name(1..Name'Last) := Name(Name'First..Name'Last);
        P.Ticket := Integer'Value(Ticket);

        P.Size := Name'Last;

        -- if both of the queues are full
        if Queue_Is_Full(Wqueue(1)) AND Queue_Is_Full(Wqueue(2)) then
            Put_Line(P.Name(1..P.Size) & " desistiu, filas cheias.");

        -- insert at the first queue
        elsif Inserted mod 2 = 0 then
            Queue_Push(Wqueue(1), P);
            Put_Line(P.Name(1..P.Size) & " entrou na fila 0.");
            Inserted := Inserted + 1;

        -- insert at the second queue
        else
            Queue_Push(Wqueue(2), P);
            Put_Line(P.Name(1..P.Size) & " entrou na fila 1.");
            Inserted := Inserted + 1;

        end if;
    end;

    procedure Vende (Wqueue: in out Two_Queue; Window: in out Two_Stack;
        NumStr: String; Sold: in out Integer) is
        P   : Person;
        Num : Integer := Integer'Value(NumStr);
        Tn  : Integer;
    begin
        -- check if the queue is empty
        -- there is nobody to sell the ticket to
        if Queue_Is_Empty(Wqueue(Num+1)) then
            Put_Line("Fila" & Num'Image & " vazia!");

        -- check if the window is empty
        -- there is no ticket to sell
        elsif Stack_Is_Empty(Window(Num+1)) then
            P := Queue_Pop(Wqueue(Num+1));
            Put_Line("Guiche" & Num'Image & " sem ingressos!" & " " & 
                P.Name(1..P.Size) & " triste.");

        -- sell the ticket
        else
            -- get the person information
            P := Queue_Pop(Wqueue(Num+1));

            loop
                exit when P.Ticket = 0;
                exit when Stack_Is_Empty(Window(Num+1));

                -- get the ticket number
                Tn := Stack_Pop(Window(Num+1));

                Put(P.Name(1..P.Size) & " comprou ingresso #");
                Put(Tn, Width => 0);
                Put_Line(".");

                Sold := Sold + 1;
            end loop;
        end if;
    end;

    procedure Carrega (Window: in out Two_Stack; End_Str: String;
    Start_Str: String; NumStr: String) is
        Num       : Integer := Integer'Value(NumStr);
        Start_Num : Integer := Integer'Value(Start_Str);
        End_Num   : Integer := Integer'Value(End_Str);
        Nrange    : Integer := End_Num - Start_Num + 1;
    begin
        for I in Start_Num..End_Num loop
            Stack_Push(Window(Num+1), I);
        end loop;

        Put(Nrange, Width => 0);
        Put_Line(" ingresso(s) carregado(s) no guiche " & Num'Image);
    end;

begin
    null;
end Utility;
