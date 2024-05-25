package Data_Structure is

    type Person is record
        Name:   String (1..20);
        Size:   Integer := 0; -- name size
        Ticket: Integer;      -- how many tickets that person wants to buy
    end record;

    type Array_Person  is array (1..20)   of Person;
    type Array_Integer is array (1..2000) of Integer;

    type Operation is (PUSH, POP);
    type Queue is record
        Data:   Array_Person;
        First:  Integer := 1;
        Insert: Integer := 1;
        Last:   Operation := POP;
    end record;

    type Stack is record
        Data:   Array_Integer;
        Top:    Integer := 0;
    end record;

    type Two_Queue is array (1..2) of Queue;
    type Two_Stack is array (1..2) of Stack;

    -- procedure
    procedure Queue_Push (Q: in out Queue; P: Person);
    procedure Stack_Push (S: in out Stack; I: Integer);

    -- function
    function  Queue_Pop (Q: in out Queue) return Person;
    function  Stack_Pop (S: in out Stack) return Integer;

    function  Queue_Is_Empty (Q: Queue) return Boolean;
    function  Stack_Is_Empty (S: Stack) return Boolean;

    function  Queue_Is_Full  (Q: Queue) return Boolean;
    function  Stack_Is_Full  (S: Stack) return Boolean;

end Data_Structure;
