from typing import Dict, TypedDict
from langgraph.graph import StateGraph
import io

from PIL import Image

class AgentState(TypedDict): # State Schema
    message : str


def greeting_node(state: AgentState) -> AgentState:
    """Node that adds a greeting to the state"""

    state['message'] = "Hello " + state["message"] + ", how is your day going?"
    return state


graph = StateGraph(AgentState)

graph.add_node("greeting", greeting_node)

graph.set_entry_point("greeting")
graph.set_finish_point("greeting")

app = graph.compile()

print_graph(app)
