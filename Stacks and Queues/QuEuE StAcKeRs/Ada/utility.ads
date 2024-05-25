with Data_Structure;                    use Data_Structure;

package Utility is

    function Get_Next_Word (Source: String; Start_Index: in out Integer)
        return String;

    procedure Chega (Wqueue: in out Two_Queue; Ticket: String; Name: String;
        Inserted: in out Integer);

    procedure Vende (Wqueue: in out Two_Queue; Window: in out Two_Stack;
        NumStr: String; Sold: in out Integer);

    procedure Carrega (Window: in out Two_Stack; End_Str: String;
        Start_Str: String; NumStr: String);

end Utility;
