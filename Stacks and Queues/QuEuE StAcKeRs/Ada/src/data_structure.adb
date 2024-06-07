with Ada.Text_IO;                       use Ada.Text_IO;

package body Data_Structure is

    -- push a person to the window queue
    procedure Queue_Push (Q: in out Queue; P: Person) is
    begin
        Q.Data(Q.Insert + 1) := P;
        Q.Insert := (Q.Insert + 1) mod 20;
        Q.Last := PUSH;
    end;

    -- push a ticket to the window stack
    procedure Stack_Push (S: in out Stack; I: Integer) is
    begin
        S.Top := S.Top + 1;
        S.Data(S.Top) := I;
    end;

    -- pop a person from the window queue
    function Queue_Pop (Q: in out Queue) return Person is
        Ret : Person;
    begin
        Ret := Q.Data(Q.First + 1);
        Q.First := (Q.First + 1) mod 20;
        Q.Last := POP;
        return Ret;
    end;

    -- pop a ticket from a window stack
    function Stack_Pop (S: in out Stack) return Integer is
        Ret : Integer;
    begin
        Ret := S.Data(S.Top);
        S.Top := S.Top - 1;
        return Ret;
    end;

    -- check if the queue is empty
    function Queue_Is_Empty (Q: Queue) return Boolean is
    begin
        if Q.First = Q.Insert AND Q.Last = POP then
            return True;
        end if;
        return False;
    end;

    -- check if the stack is empty
    function Stack_Is_Empty (S: Stack) return Boolean is
    begin
        return S.Top = 0;
    end;

    -- check if the queue is full
    function Queue_Is_Full (Q: Queue) return Boolean is
    begin
        if Q.First = Q.Insert AND Q.Last = PUSH then
            return True;
        end if;
        return False;
    end;

    -- check if the stack is full
    function Stack_Is_Full (S: Stack) return Boolean is
    begin
        return S.Top = 20;
    end;

    -- return how filled the queue is
    function Queue_Size (Q: Queue) return Integer is
    begin
        return abs (Q.First - Q.Insert);
    end;

    -- return how filled the stack is
    function Stack_Size (S: Stack) return Integer is
    begin
        return S.Top;
    end;

begin
    null;
end Data_Structure;
