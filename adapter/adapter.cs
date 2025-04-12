using System;

// 내부 클래스 (클라이언트가 기대하는 인터페이스)
interface IInternalClass
{
    string Fetch();
}

// 외부 클래스 (인터페이스가 다름)
class ExternalClass
{
    public string Search()
    {
        return "get user info";
    }
}

// 어댑터 클래스
class Adapter : IInternalClass
{
    private ExternalClass external;

    public Adapter(ExternalClass ext)
    {
        external = ext;
    }

    public string Fetch()
    {
        return external.Search();
    }
}

class Program
{
    static void Main()
    {
        ExternalClass external = new ExternalClass();
        IInternalClass adapter = new Adapter(external);

        Console.WriteLine(adapter.Fetch());  // "get user info"
    }
}
