import dns.resolver

domain = input("Enter the domain: ")

# list of common DNS records
records = ['A', 'AAAA', 'CNAME', 'MX', 'NS', 'PTR', 'SOA', 'SRV', 'TXT']

# loop through each record type, print results
for record in records:
    try:
        print(f"\n{record} Record:")
        answers = dns.resolver.resolve(domain, record).response.answer
        for rdata in answers:
            print(rdata)
        print()
    except Exception as e:
        print(e)