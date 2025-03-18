# My NCAE Regionals CTF Answers

My approaches to CTF questions I answered.

## OSINT

- Question 1 is simple Google search.
- Question 2 requires looking up Maltek Solution on the [New York Department of State business entity public database](https://apps.dos.ny.gov/publicInquiry/).
- Question 3 requires querying DNS records to find the hidden flag. Wrote a simple Python script to query common DNS records, eventually found flag in TXT record.

## Exploitation

Port scanner is a website with inputs hostname and port. The idea to derive solution is to inject commands into the input, for example entering: `127.0.0.1; cat flag.txt`.

## Networking

We are given a PCAP files, which we can use Wireshark to inspect.

## SOC

First few SOCs were simple Google search. Rest of SOC requires searching and filtering logs on Cyberlabs platform, I used both Splunk GUI and the Cyberlabs CLI to do so.

## Trivia

Just Google searches.

## Cryptography

Didn't do.

## Binary Exploitation

Didn't do.
