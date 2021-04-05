from typing import List, Text


class NoAgentFoundException(Exception):
    pass


class Agent(object):
    def __init__(self, name,skills,load):
        self.name = name
        self.skills = skills
        self.load = load

    def __str__(self):
        return "<Agent: {}>".format(self.name)


class Ticket(object):
    Id = []

    def __init__(self, object):
        if(object.id in Ticket.Id or not object.restrictions):
            pass
        else:
            Ticket.Id.append(object.id)
            self.id = object.id
            self.restrictions = object.restrictions


class FinderPolicy(object):
    def _filter_loaded_agents(self, agents: List[Agent]) -> List[Agent]:
        pass

    def find(self, ticket: Ticket, agents: List[Agent]) -> Agent:
        if not agents:
            raise NoAgentFoundException


class LeastLoadedAgent(FinderPolicy):  # 짐 가장 적은agent뽑음
    def find(self, ticket: Ticket, agents: List[Agent]) -> Agent:
        res = agents[0]
        for agent in agents:
            if agent.load < res.load:
                res = agents[0]
        return res


class LeastFlexibleAgent(FinderPolicy):
    def find(self, ticket: Ticket, agents: List[Agent]) -> Agent:
        res = None
        for agent in agents:
            if agent._skills in ticket:
                if res is None or res._load > agent._load:
                    res = agent
        if res is None:
            raise NoAgentFoundException
        else:
            return res
